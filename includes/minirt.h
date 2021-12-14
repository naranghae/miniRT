/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 21:27:09 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minirt_const.h"
# include "mlx.h"
# include "color.h"
# include "vector.h"
# include "parse_element.h"
# include "get_next_line.h"
# include "rt_info.h"
# include "minirt_bonus.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_imgs
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void		*img;
	char		*addr;
}				t_imgs;

typedef struct	s_mw
{
	void		*mlx_p;
	void		*win_p;
}				t_mw;

typedef struct	s_data
{
	int			i;
	t_mw		*mlx;
	t_list		*lst_imgs;
}				t_data;

typedef struct	s_bmp
{
	int			fd;
	char		*name;
	char		*file;
}				t_bmp;

typedef struct	s_livar
{
	void		*object;
	t_list		*lights;
	t_light		*light;
	t_hit		*hit_object;
	t_ray		to_light;
	t_rgb		diff_spec;
	t_rgb		light_color;
	t_vec		v;
	t_vec		r;
	t_rgb		specular_color;
	t_rgb		diffuse_color;
	double		diffuse;
	double		specular;
}				t_livar;

typedef struct	s_mkvar
{
	t_area		pixel;
	t_ray		ray;
	t_rgb		color;
	void		*object;
	t_hit		*hit;
}				t_mkvar;

int				ft_key_press(int key, t_data *data);
t_mw			*malloc_mlx(void);
int				*init_img(t_data *data, t_rt_info *info, t_area *resolution);
void			my_mlx_pixel_put(t_imgs *data, t_area pixel, int color);
int				is_space(char str);
void			next_space(char **str);
void			next_element(char **str);
void			next_thing(char **str);
char			*ft_split_type(char **line);
void			ft_parsing(t_rt_info *info, char **line);
void			line_parsing(t_rt_info *info, char *line);
t_rt_info		*rt_save(int fd);
t_rt_info		*put_info(char **av);
void			start_error_check(int ac, char **av);
void			ft_error(int i);
void			*init_info(t_rt_info *info);
void			init_licolor(t_livar *var);
void			init_resol(t_mkvar *var, t_rt_info *info, t_camera *camera);
void			light_check(t_livar *var, t_ray ray, t_rt_info *info,
				t_hit *hit);
void			light_calc(t_livar *var, t_hit *hit);
int				lst_free(t_list **head);
int				rt_free(t_rt_info *info);
int				sp_free(t_list *lst_sp);
int				pl_free(t_list *lst_pl);
int				sq_free(t_list *lst_sq);
int				tr_free(t_list *lst_tr);
int				cy_free(t_list *lst_cy);
void			set_resolution(t_rt_info *info, char **line);
void			set_ambient_lighting(t_rt_info *info, char **line);
void			set_camera(t_rt_info *info, char **line);
void			set_light(t_rt_info *info, char **line);
void			set_sphere(t_rt_info *info, char **line);
void			set_plane(t_rt_info *info, char **line);
void			set_square(t_rt_info *info, char **line);
void			set_triangle(t_rt_info *info, char **line);
void			set_cylinder(t_rt_info *info, char **line);
double			get_radian(double degree);
void			ft_swap(double *a, double *b);
double			ft_max(double a, double b);
int				sp_quadratic_equation(t_vec vec, double *t1, double *t2);
void			ray_sphere(t_ray ray, t_rt_info *info, t_hit *hit,
				void **object);
int				intersect_sphere(t_ray ray, t_sphere sp, t_hit *hit);
void			ray_plane(t_ray ray, t_rt_info *info, t_hit *hit, void
				**object);
int				intersect_plane(t_ray ray, t_plane plane, t_hit *hit);
double			pl_solve(t_ray ray, t_vec nv, t_vec pos);
void			ray_square(t_ray ray, t_rt_info *info, t_hit *hit, void
				**object);
int				intersect_square(t_ray ray, t_square square, t_hit *hit);
int				ft_parallel(t_vec a, t_vec b);
void			ft_axis_rotation(t_vec angle, t_vec *vec);
int				intersect_triangle(t_ray ray, t_triangle tr, t_hit *hit);
void			ray_triangle(t_ray ray, t_rt_info *info, t_hit *hit,
				void **object);
int				intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit, int i);
void			ray_cylinder(t_ray ray, t_rt_info *info, t_hit *hit,
				void **object);
int				intersect_disk(t_ray ray, t_cylinder cy, t_hit *hit,
				t_vec disk_pos);
double			cy_calc(t_cyvar var, t_hit *hit, int i);
double			intersect_check(t_cyvar var, double *t1, double *t2, int i);
void			t_select(double *t1, double *t2, int i);
int				cy_boundary(t_ray ray, t_cylinder cy, t_cyvar var);
t_vec			get_cy_normal(t_vec pos, t_cylinder cy);
void			make_img(t_imgs *img, t_rt_info *info, t_camera *camera);
t_ray			new_ray(t_vec orig, t_vec dir);
t_vec			set_cam(double fov, t_area resolution, int y, int x);
t_ray			create_ray(t_camera *camera, t_rt_info *info,
				t_area pixel);
t_vec			ft_ray_at(t_ray ray, double t);
t_hit			*ray_object(t_ray ray, t_rt_info *info, void **object);
int				*show_light(t_ray ray, t_rt_info *info, t_hit *hit,
				t_rgb *color);
int				ft_rt_atoi(char **str);
double			ft_rt_atod(char **str);
double			ft_atod(char *str);
void			circle_lstadd(t_list **lst, t_list *new);
void			bmp_save(t_data *data, t_area win, char *filename);
#endif
