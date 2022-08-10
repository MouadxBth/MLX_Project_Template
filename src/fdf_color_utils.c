/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:38:58 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/08 16:16:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_transparency(int color)
{
	return ((color >> 24) & 0xff);
}

int	get_red(int color)
{
	return ((color >> 16) & 0xff);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xff);
}

int	get_blue(int color)
{
	return (color & 0xff);
}

int	mix_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
