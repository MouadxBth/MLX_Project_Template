/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:23:48 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/06 17:19:41 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

static void	pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= W_WIDTH) && (y >= 0 && y <= W_HEIGHT))
	{
		dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw(t_vector *vector, t_fdf *info)
{
	int	error;
	int	color;

	color = 0xffffff;
	if (vector->start.z || vector->end.z)
		color = 0xff0000;
	while (1)
	{
		pixel_put(&info->image, vector->start.x, vector->start.y, color);
		if (is_point(vector))
			break ;
		error = vector->delta.z * 2;
		if (error >= vector->delta.y)
		{
			if (vector->start.x == vector->end.x)
				break ;
			vector->delta.z += vector->delta.y;
			vector->start.x += vector->x_direction;
		}
		if (error <= vector->delta.x)
		{
			if (vector->start.y == vector->end.y)
				break ;
			vector->delta.z += vector->delta.x;
			vector->start.y += vector->y_direction;
		}
	}
}

void	render_map(t_fdf *info)
{
	int		x;
	int		y;
	t_vector	right;
	t_vector	down;

	y = -1;
	while (++y < info->map.height)
	{
		x = -1;
		while (++x < info->map.width)
		{
			if (x < info->map.width - 1)
			{
				right = new_vector(project_point(info->map.matrix[y][x], info),
					project_point(info->map.matrix[y][x + 1], info));
				draw(&right, info);
			}
			if (y < info->map.height - 1)
			{
				down = new_vector(project_point(info->map.matrix[y][x], info),
					project_point(info->map.matrix[y + 1][x], info));
				draw(&down, info);
			}
		}
	}
	mlx_put_image_to_window(info->mlx, info->mlx_window, info->image.id, 0, 0);
}
