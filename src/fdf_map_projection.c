/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:25:06 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/09 15:03:49 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

/*point->x = (x - y) * cos(angle);
point->y = (x + y) * sin(angle)  - point->z;
point->x = x - y;
point->y = y + x - point->z;*/
static void	isometric(t_point *point, float angle)
{
	int	x;
	int	y;

	x = point->x;
	y = point->y;
	point->x = (x * cos(angle) - y * sin(angle)) * 2;
	point->y = ((x * sin(angle) + y * cos(angle)) - point->z);
}

static void	rotate(t_point *point, float angle)
{
	int	x;
	int	y;

	x = point->x;
	y = point->y;
	point->x = (x * cos(angle) - y * sin(angle));
	point->y = (x * sin(angle) + y * cos(angle));
}

t_point	project_point(t_point point, t_fdf *info)
{	
	point.x *= info->map.scale;
	point.y *= info->map.scale;
	rotate(&point, info->camera.rotation_angle);
	if (point.z)
		point.z *= info->camera.altitude;
	if (info->camera.iso_projection)
		isometric(&point, info->camera.iso_angle);
	point.x += info->map.x_offset;
	point.y += info->map.y_offset;
	point.color = select_color(info->map.z_max, info->map.z_min, point.z);
	return (point);
}
