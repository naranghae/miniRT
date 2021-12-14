/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 16:48:00 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H
# include "rt_info.h"

typedef struct	s_cone
{
	t_vec		pos;
	t_vec		normal_vec;
	t_vec		h;
	double		height;
	double		r;
	t_rgb		color;
}				t_cone;

typedef struct	s_covar
{
	t_vec		h_hat;
	t_vec		v;
	t_vec		w;
	double		m;
	double		a;
	double		b;
	double		c;
	double		t;
	double		t1;
	double		t2;
}				t_covar;

typedef struct	s_cube
{
	double		size;
	t_vec		pos;
	t_vec		x_m;
	t_vec		x_p;
	t_vec		y_m;
	t_vec		y_p;
	t_vec		z_m;
	t_vec		z_p;
	t_rgb		color;
}				t_cube;

typedef struct	s_pyramid
{
	double		size;
	t_vec		pos;
	t_vec		p1;
	t_vec		p2;
	t_vec		p3;
	t_vec		p4;
	t_vec		top;
	t_rgb		color;
}				t_pyramid;

typedef struct	s_pyvar
{
	t_vec		p1;
	t_vec		p2;
	t_vec		p3;
	t_vec		p4;
}				t_pyvar;

void			filter_check(t_rt_info *info, char **line);
void			set_cone(t_rt_info *info, char **line);
int				intersect_cone(t_ray ray, t_cone cube, t_hit *hit);
void			ray_cone(t_ray ray, t_rt_info *info, t_hit *hit,
				void **object);
int				co_discriminant(t_vec vec, double *t1, double *t2);
void			cone_calc(t_covar *var, t_cone cone, t_ray ray);
t_vec			get_co_normal(t_vec pos, t_cone co);
int				co_boundary(t_ray ray, t_cone co, double t);
int				co_free(t_list *lst_co);
void			set_cube(t_rt_info *info, char **line);
void			set_pyramid(t_rt_info *info, char **line);
void			ob_five(t_pyramid *py);
t_pyvar			py_dot_create(t_vec	a, t_vec b, t_vec c);
void			sepia_color(t_rgb *rgb);

#endif
