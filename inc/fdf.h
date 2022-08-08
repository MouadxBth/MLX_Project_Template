/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:06:24 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/07 21:41:19 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define W_WIDTH 1366
# define W_HEIGHT 768

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_vector
{
	t_point	start;
	t_point	end;
	t_point	delta;
	int	x_direction;
	int	y_direction;
}	t_vector;

typedef struct s_camera
{
	int	altitude;
	int	altitude_threshold;
	float	axis_angle;
	float	ordinate_angle;
	float	altitude_angle;
	float	iso_angle;
}	t_camera;

typedef struct s_image
{
	void	*id;
	char	*address;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_image;

typedef struct s_fdf_map
{
	int	width;
	int	height;
	int	scale;
	int	x_offset;
	int	y_offset;
	t_point	**matrix;
}	t_fdf_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_window;
	t_camera	camera;
	t_image		image;
	t_fdf_map	map;
}	t_fdf;

void	clear_image(t_image *image);
void	fill_image(t_image *info, int color);
int	close_window(t_fdf *info);
void	error(char *msg);
void	check_args(int argc, char **argv);

int	is_point(t_vector *vector);
t_vector	new_vector(t_point start, t_point end);

void	rotate_axis(t_point *point, float angle);
void	rotate_ordinate(t_point *point, float angle);
void	rotate_altitude(t_point *point, float angle);

void	scale_point(t_point *point, int scale);
void	offset_point(t_point *point, int x_offset, int y_offset);
void	isometric(t_point *point, float angle);

int	ft_file_rows(char *file);
int	ft_file_columns(char *file);

void	init_window(t_fdf *info);
void	init_map(t_fdf_map *map, char *file);
void	init_image(t_fdf *info);
void	init_camera(t_camera *info);

void	parse_map(t_fdf_map *map, char *file);
void	print_map(t_fdf_map *map);
t_point	project_point(t_point point, t_fdf *info);
void	render_map(t_fdf *info);

int	handle_exit(int key, t_fdf *info);
int	handle_keys(int key, t_fdf *info);


#endif
