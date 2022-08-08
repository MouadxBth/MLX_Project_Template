/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:06:58 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 23:44:27 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	init_window(t_fdf *info)
{
	if (!info)
		error("Could not initialize window");
	info->mlx = mlx_init();
	info->mlx_window = mlx_new_window(info->mlx, W_WIDTH, W_HEIGHT, "FDF");
}

void	init_image(t_fdf *info)
{
	info->image.id = mlx_new_image(info->mlx, W_WIDTH, W_HEIGHT);
	info->image.address = mlx_get_data_addr(info->image.id,
			&info->image.bits_per_pixel,
			&info->image.line_length,
			&info->image.endian);
}

void	init_map(t_fdf_map *map, char *file)
{
	int	index;

	if (!map || !file)
		error("Could not initialize map");
	map->width = ft_file_columns(file);
	map->height = ft_file_rows(file);
	map->scale = 1;
	map->x_offset = 0;/*(W_WIDTH - (map->width * map->scale)) / 2;*/
	map->y_offset = 0;/*(W_HEIGHT - (map->height * map->scale)) / 2;*/
	map->matrix = (t_point **)calloc(map->height, sizeof(t_point *));
	if (!map->matrix)
		error("Could not allocate enough memory for fdf map");
	index = -1;
	while (++index < map->height)
	{
		map->matrix[index] = (t_point *)ft_calloc(map->width, sizeof(t_point));
		if (!map->matrix[index])
			error("Could not allocate enough memory for fdf map");
	}
}

void	init_camera(t_camera *camera)
{
	if (!camera)
		error("Could not initialize camera");
	camera->altitude = 5;
	camera->altitude_threshold = 10;
	camera->axis_angle = 0;
	camera->ordinate_angle = 0;
	camera->altitude_angle = 0;
	camera->iso_angle = (1.0 / 4.0) * 3.14;
}
