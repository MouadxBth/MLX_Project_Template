/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:25:06 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 19:04:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"


void	isometric(t_point *point, float angle)
{
	int	x;
	int	y;

	x = point->x;
	y = point->y;
	//point->x = (x - y) * cos(angle);
	//point->y = (x + y) * sin(angle)  - point->z;
	//point->x = x - y;
	//point->y = y + x - point->z;
	point->x = (x * cos(angle) - y * sin(angle)) *2;
	point->y = (x * sin(angle) + y * cos(angle)) - point->z;
}

void	rotate(t_point *point, t_camera *camera)
{
	rotate_axis(point, camera->axis_angle);
	rotate_ordinate(point, camera->ordinate_angle);
	rotate_altitude(point, camera->altitude_angle);
}

void	altitude(t_point *point, t_camera *camera)
{
	if (point->z >= camera->altitude_threshold)
		point->z += camera->altitude;
}

t_point	project_point(t_point point, t_fdf *info)
{	
	scale_point(&point, info->map.scale);
	rotate(&point, &info->camera);
	altitude(&point, &info->camera);
	isometric(&point, info->camera.iso_angle);
	offset_point(&point, info->map.x_offset, info->map.y_offset);
	return (point);
}
