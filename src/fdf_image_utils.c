/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:19 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 19:04:14 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int	clear_image(t_image *image)
{
	if (!image)
		return (error("Could not clear image"));
	ft_bzero(image->address,
		(W_WIDTH - (W_WIDTH / 5)) * W_HEIGHT
		* (image->bits_per_pixel / 8));
	return (1);
}

int	fill_image(t_image *image, int color)
{
	int	*background;
	int	index;

	if (!image)
		return (error("Could not fill image"));
	background = (int *)(image->address);
	index = -1;
	while (++index < W_HEIGHT * W_WIDTH)
		background[index] = color;
	return (1);
}

int	cleanup(t_fdf *info)
{
	int	index;

	index = -1;
	while (++index < info->map.height)
		free(info->map.matrix[index]);
	free(info->map.matrix);
	mlx_destroy_image(info->mlx, info->image[0].id);
	mlx_destroy_image(info->mlx, info->image[1].id);
	mlx_destroy_window(info->mlx, info->mlx_window);
	exit(-1);
	return (0);
}
