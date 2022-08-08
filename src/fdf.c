/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:20:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 21:33:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	setup_event_hooks(t_fdf *info)
{
	mlx_key_hook(info->mlx_window, handle_exit, info);
	mlx_hook(info->mlx_window, 17, 0, close_window, info);
	mlx_hook(info->mlx_window, 2, 1L << 0, handle_keys, info);
}

int	main(int argc, char **argv)
{
	t_fdf	info;

	check_args(argc, argv);
	init_window(&info);
	init_image(&info);
	init_map(&info.map, argv[1]);
	init_camera(&info.camera);
	parse_map(&info.map, argv[1]);
	print_map(&info.map);
	render_map(&info);
	setup_event_hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
