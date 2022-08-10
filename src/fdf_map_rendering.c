/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:23:48 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 19:03:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

static int	in_window(t_point *point)
{
	return ((point->x > 0 && point->x <= W_WIDTH - (W_WIDTH / 5))
		&& (point->y >= 0 && point->y <= W_HEIGHT));
}

static void	pixel_put(t_image *img, t_point *point, int color)
{
	int	step;

	step = (point->y * img->line_length
			+ point->x * (img->bits_per_pixel / 8));
	img->address[step] = color;
	img->address[++step] = color >> 8;
	img->address[++step] = color >> 16;
	img->address[++step] = color >> 24;
}

static void	draw(t_vector *vector, t_fdf *info)
{
	int		error;
	t_point	current;

	current = vector->start;
	while (current.x != vector->end.x || current.y != vector->end.y)
	{
		if (in_window(&current))
			pixel_put(&info->image[info->c_img], &current,
				get_color(vector, &current));
		if (point_collision(&current, &vector->end))
			break ;
		error = vector->delta.z * 2;
		if (error >= vector->delta.y)
		{
			vector->delta.z += vector->delta.y;
			current.x += vector->x_direction;
		}
		if (error <= vector->delta.x)
		{
			vector->delta.z += vector->delta.x;
			current.y += vector->y_direction;
		}
	}
}

static void	render_row(t_fdf *info, int x, int y)
{
	t_vector	line;

	if (x < info->map.width - 1)
	{
		line = new_vector(project_point(info->map.matrix[y][x], info),
				project_point(info->map.matrix[y][x + 1], info));
		draw(&line, info);
	}
	if (y < info->map.height - 1)
	{
		line = new_vector(project_point(info->map.matrix[y][x], info),
				project_point(info->map.matrix[y + 1][x], info));
		draw(&line, info);
	}
}

int	render_map(t_fdf *info)
{
	int		x;
	int		y;

	if (!info)
		return (error("Could not render map"));
	y = -1;
	while (++y < info->map.height)
	{
		x = -1;
		while (++x < info->map.width)
			render_row(info, x, y);
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window,
		info->image[info->c_img].id, 0, 0);
	info->c_img = !info->c_img;
	return (1);
}
