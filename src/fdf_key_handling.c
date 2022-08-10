/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:16:46 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 17:08:40 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	handle_zoom(int key, t_fdf *info)
{
	if (key == 65451)
		info->map.scale += 1;
	else if (key == 65453)
		info->map.scale -= 1;
	info->map.z_max = info->map.z_max_orig * info->map.scale;
	info->map.z_min = info->map.z_min_orig * info->map.scale;
}

static void	handle_translation(int key, t_fdf *info)
{
	if (key == 65361)
		info->map.x_offset -= 10;
	else if (key == 65362)
		info->map.y_offset -= 10;
	else if (key == 65363)
		info->map.x_offset += 10;
	else if (key == 65364)
		info->map.y_offset += 10;
}

static int	is_key(int key)
{
	return (key == 65451 || key == 65453
		|| key == 65361 || key == 65362
		|| key == 65363 || key == 65364
		|| key == 65430 || key == 65432
		|| key == 65431 || key == 65437
		|| key == 65429);
}

int	handle_keys(int key, t_fdf *info)
{
	if (key == 65451 || key == 65453)
		handle_zoom(key, info);
	else if (key == 65429)
		info->camera.iso_projection = !info->camera.iso_projection;
	else if (key == 65430)
		info->camera.altitude += 1;
	else if (key == 65432)
		info->camera.altitude -= 1;
	else if (key == 65431)
		info->camera.rotation_angle -= 0.01;
	else if (key == 65437)
		info->camera.rotation_angle += 0.01;
	else if (key == 65361 || key == 65362
		|| key == 65363 || key == 65364)
		handle_translation(key, info);
	if (is_key(key))
	{
		clear_image(&info->image[!info->c_img]);
		render_map(info);
	}
	return (0);
}

int	handle_exit(int key, t_fdf *info)
{
	if (key == 65307)
		cleanup(info);
	return (0);
}
