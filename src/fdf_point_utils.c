/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:25:54 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/06 00:34:27 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	scale_point(t_point *point, int scale)
{
	point->x *= scale;
	point->y *= scale;
}

void	offset_point(t_point *point, int x_offset, int y_offset)
{
	point->x += x_offset;
	point->y += y_offset;
}

void	rotate_axis(t_point *point, float angle)
{
	float y;

	y = point->y;
	point->y = y * cos(angle) + point->z * sin(angle);
	point->z = -y * sin(angle) + point->z * cos(angle);
}

void	rotate_ordinate(t_point *point, float angle)
{
	float x;

	x = point->x;
	point->x = x * cos(angle) + point->z * sin(angle);
	point->z = -x * sin(angle) + point->z * cos(angle);
}

void	rotate_altitude(t_point *point, float angle)
{
	float x;
	float y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

t_point	new_point(int x, int y, int z)
{
	t_point	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
