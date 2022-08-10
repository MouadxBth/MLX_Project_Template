/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:27:54 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 19:06:47 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	string_put(t_fdf *info, int y_offset, int color, char *str)
{
	mlx_string_put(info->mlx, info->mlx_window,
		(W_WIDTH - (W_WIDTH / 5)) + 15, 15 + y_offset,
		color, str);
}

void	print_menu(t_fdf *info)
{
	string_put(info, 0, 0xffbf00, "Welcome to FDF!");
	string_put(info, 20, 0xffcf40, "Translate the map:");
	string_put(info, 40, 0xffffff, "->Left: LEFT");
	string_put(info, 60, 0xffffff, "->Right: RIGHT");
	string_put(info, 80, 0xffffff, "->Up: UP");
	string_put(info, 100, 0xffffff, "->Down: DOWN");
	string_put(info, 120, 0xffcf40, "Rotate the map:");
	string_put(info, 140, 0xffffff, "->Positive: Numpad 8");
	string_put(info, 160, 0xffffff, "->Negative: Numpad 5");
	string_put(info, 180, 0xffcf40, "Alter altitude:");
	string_put(info, 200, 0xffffff, "->Increase: Numpad 4");
	string_put(info, 220, 0xffffff, "->Decrease: Numpad 6");
	string_put(info, 240, 0xffcf40, "Projection:");
	string_put(info, 260, 0xffffff, "->Isometric: Numpad 7");
	string_put(info, 280, 0xffffff, "->Parallel: Numpad 7");
	string_put(info, 300, 0xff0000, "Exit: ESC");
}
