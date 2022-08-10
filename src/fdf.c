/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:20:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 18:59:22 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	setup_event_hooks(t_fdf *info)
{
	mlx_key_hook(info->mlx_window, handle_exit, info);
	mlx_hook(info->mlx_window, 17, 0, cleanup, info);
	mlx_hook(info->mlx_window, 2, 1L << 0, handle_keys, info);
}

int	main(int argc, char **argv)
{
	t_fdf	info;

	if (!check_args(argc, argv))
		return (-1);
	if (!init_window(&info))
		return (-1);
	if (!init_map(&info.map, argv[1]))
		return (-1);
	if (!init_image(&info) || !init_camera(&info.camera))
		cleanup(&info);
	parse_map(&info.map, argv[1]);
	if (!render_map(&info))
		cleanup(&info);
	print_menu(&info);
	setup_event_hooks(&info);
	mlx_loop(info.mlx);
	cleanup(&info);
	return (0);
}
