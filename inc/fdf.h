/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:06:24 by mbouthai          #+#    #+#             */
/*   Updated: 2022/08/10 19:00:54 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define W_WIDTH 1000
# define W_HEIGHT 500

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_vector
{
	t_point	start;
	t_point	end;
	t_point	delta;
	int		x_direction;
	int		y_direction;
}	t_vector;

typedef struct s_camera
{
	int		altitude;
	int		altitude_threshold;
	int		iso_projection;
	float	rotation_angle;
	float	iso_angle;
}	t_camera;

typedef struct s_image
{
	void	*id;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fdf_map
{
	int		width;
	int		height;
	int		scale;
	int		x_offset;
	int		y_offset;
	int		z_max_orig;
	int		z_min_orig;
	int		z_max;
	int		z_min;
	t_point	**matrix;
}	t_fdf_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*mlx_window;
	int			c_img;
	t_camera	camera;
	t_image		image[2];
	t_fdf_map	map;
}	t_fdf;

int			error(char *msg);
int			check_args(int argc, char **argv);

int			clear_image(t_image *image);
int			fill_image(t_image *info, int color);
int			cleanup(t_fdf *info);

int			ft_file_rows(char *file);
int			ft_file_columns(char *file);

int			get_transparency(int color);
int			get_red(int color);
int			get_green(int color);
int			get_blue(int color);
int			mix_color(int t, int r, int g, int b);

int			select_color(int max, int min, int z);
int			get_color(t_vector *line, t_point *current);

int			point_collision(t_point *start, t_point *end);

int			init_window(t_fdf *info);
int			init_image(t_fdf *info);
int			init_map(t_fdf_map *map, char *file);
int			init_camera(t_camera *info);

void		parse_map(t_fdf_map *map, char *file);
void		print_map(t_fdf_map *map);
int			render_map(t_fdf *info);
void		print_menu(t_fdf *info);

int			handle_exit(int key, t_fdf *info);
int			handle_keys(int key, t_fdf *info);

t_vector	new_vector(t_point start, t_point end);
t_point		project_point(t_point point, t_fdf *info);

#endif
