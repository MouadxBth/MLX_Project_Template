/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vector_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:43:33 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/06 17:16:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_point(t_vector *vector)
{
	return (vector->start.x == vector->end.x &&
		vector->start.y == vector->end.y);
}

t_vector	new_vector(t_point start, t_point end)
{
	t_vector	result;
	result.start = start;
	result.end = end;
	result.delta.x = ft_abs(end.x - start.x);
	result.delta.y = -ft_abs(end.y - start.y);
	result.delta.z = result.delta.x + result.delta.y;
	if (start.x < end.x)
		result.x_direction = 1;
	else
		result.x_direction = -1;
	if (start.y < end.y)
		result.y_direction = 1;
	else
		result.y_direction = -1;
	return (result);
}
