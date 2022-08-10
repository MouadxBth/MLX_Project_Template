/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:09:26 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/09 15:05:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static void	fill_map_matrix_row(t_fdf_map *map, char *str, int row)
{
	int		column;
	char	**values;

	if (!str || !map)
		return ;
	column = -1;
	values = ft_split(str, ' ');
	while (values[++column])
	{
		map->matrix[row][column].x = column;
		map->matrix[row][column].y = row;
		map->matrix[row][column].z = ft_atoi(values[column]);
		if (map->matrix[row][column].z > map->z_max_orig)
			map->z_max_orig = map->matrix[row][column].z;
		else if (map->matrix[row][column].z < map->z_min_orig)
			map->z_min_orig = map->matrix[row][column].z;
		free(values[column]);
	}
	free(values);
}

void	print_map(t_fdf_map *map)
{
	int	x;
	int	y;

	if (!map)
		return ;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ft_printf("%-3i", map->matrix[y][x].z);
		ft_printf("\n");
	}
}

void	parse_map(t_fdf_map *map, char *file)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	row = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		fill_map_matrix_row(map, line, row);
		if (line)
			row++;
		free(line);
	}
	close(fd);
}
