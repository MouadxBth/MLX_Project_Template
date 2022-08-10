/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:05:28 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/08 22:47:44 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

int	error(char *msg)
{
	if (msg)
		ft_printf("[ERROR]: %s\n", msg);
	return (0);
}

int	check_args(int argc, char **argv)
{
	char	**file;
	int		index;

	if (argc != 2)
		return (error("usage: ./fdf [map_name.fdf]"));
	file = ft_split(argv[1], '.');
	if (!file)
		return (error("unknown file format"));
	if (!file[1])
		return (error("unknown file format"));
	if (ft_memcmp(file[1], "fdf", 3) != 0)
		return (error("unknown file format"));
	index = -1;
	while (file[++index])
		free(file[index]);
	free(file);
	return (1);
}

int	ft_file_rows(char *file)
{
	int		fd;
	int		result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
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
	int		fd;
	int		result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	result = ft_words(line, ' ');
	free(line);
	close(fd);
	return (result);
}
