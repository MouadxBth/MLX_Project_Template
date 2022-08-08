/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:19 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 18:24:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	clear_image(t_image *image)
{
	ft_bzero(image->address, W_WIDTH * W_HEIGHT * (image->bits_per_pixel / 8));
}

void	fill_image(t_image *image, int color)
{
	int	*background;
	int	index;

	background = (int *)(image->address);
	index = -1;
	while (++index < W_HEIGHT * W_WIDTH)
		background[index] = color;
}

int	close_window(t_fdf *info)
{
	int	index;

	clear_image(&info->image);
	index = -1;
	while (++index < info->map.height)
		free(info->map.matrix[index]);
	free(info->map.matrix);
	mlx_destroy_image(info->mlx, info->image.id);
	mlx_destroy_window(info->mlx, info->mlx_window);
	exit(0);
	return (0);
}
