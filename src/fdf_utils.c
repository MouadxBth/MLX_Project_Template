/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:05:28 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 18:20:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"


void	error(char *msg)
{
//	int	index;

	if (msg)
		ft_printf("[ERROR]: %s\n", msg);
/*	index = -1;
	while (++index < info->map.height)
		free(info->map.matrix[index]);
	free(info->map.matrix);
	mlx_destroy_image(info->mlx, info->image.id);
	mlx_destroy_window(info->mlx, info->mlx_window);*/
	exit(-1);
}


void	check_args(int argc, char **argv)
{
	char	**file;

	if (argc != 2)
		error("usage: ./fdf [map_name.fdf]");
	file = ft_split(argv[1], '.');
	if (!file)
		error("unknown file format");
	if (!file[1])
		error("unknown file format");
	if (ft_memcmp(file[1], "fdf", 3) != 0)
		error("unknown file format");
}

int	ft_file_rows(char *file)
{
	int	fd;
	int	result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error("Could not open file");
		return (-1);
	}
	result = 0;
	line = get_next_line(fd);
	while (line)
	{
		result++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (result);
}

int	ft_file_columns(char *file)
{
	int	fd;
	int	result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error("Could not open file");
		return (-1);
	}
	line = get_next_line(fd);
	result = ft_words(line, ' ');
	free(line);
	close(fd);
	return (result);
}
