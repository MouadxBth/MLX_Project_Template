/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:16:46 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 21:47:39 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int	handle_exit(int key, t_fdf *info)
{
	if (key == 65307)
		close_window(info);
	return (0);
}

static void	handle_zoom(int key, t_fdf *info)
{
	if (key == 65451)
		info->map.scale += 1;
	else if (key == 65453)
		info->map.scale -= 1;
	clear_image(&info->image);
	render_map(info);
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
	clear_image(&info->image);
	render_map(info);
}

static void	handle_rotation(int key, t_fdf *info)
{
	if (key == 65431)
		info->camera.axis_angle -= 0.1;
	else if (key ==65437)
		info->camera.axis_angle += 0.1;
	else if (key == 65430)
		info->camera.ordinate_angle -= 0.1;
	else if	(key == 65432)
		info->camera.ordinate_angle += 0.1;
	else if (key == 65429)
		info->camera.iso_angle -= 0.1;
	else if (key == 65434)
		info->camera.iso_angle += 0.1;
	else if (key == 65436)
		info->camera.altitude_angle -= 0.1;
	else if (key == 65435)
		info->camera.altitude_angle += 0.1;
	clear_image(&info->image);
	render_map(info);
}

int	handle_keys(int key, t_fdf *info)
{
	ft_printf("%d\n", key);
	if (key == 65451 || key == 65453)
		handle_zoom(key, info);
	else if (key == 65361 || key == 65362
		|| key == 65363 || key == 65364)
		handle_translation(key, info);
	else if (key == 65431 || 65437
		|| key == 65430 || key == 65432
		|| key == 65429 || key == 65434
		|| key == 65436 || key == 65435)
		handle_rotation(key, info);

	return (0);
}
