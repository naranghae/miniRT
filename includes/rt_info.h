/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_info.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 19:41:15 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_INFO_H
# define RT_INFO_H
# include "../libft/libft.h"

typedef struct			s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_area
{
	int					w;
	int					h;
}						t_area;

typedef struct			s_am_light
{
	double				ratio;
	t_rgb				color;
}						t_am_light;

typedef struct			s_camera
{
	t_vec				view_point;
	t_vec				normal_vec;
	t_vec				lower_left_corner;
	t_vec				horizontal;
	t_vec				vertical;
	double				fov;
	double				aspect_ratio;
}						t_camera;

typedef struct			s_camvar
{
	t_vec				rot[4];
}						t_camvar;

typedef struct			s_light
{
	t_vec				light_point;
	double				ratio;
	t_rgb				color;
}						t_light;

typedef struct			s_sphere
{
	t_vec				center;
	double				radius;
	t_rgb				color;
}						t_sphere;

typedef struct			s_spvar
{
	double				t;
	double				t1;
	double				t2;
	t_vec				vec;
	double				a;
	double				b;
	double				c;
}						t_spvar;

typedef struct			s_plane
{
	t_vec				pos;
	t_vec				normal_vec;
	t_rgb				color;
}						t_plane;

typedef struct			s_square
{
	t_vec				center;
	t_vec				normal_vec;
	double				side_size;
	t_rgb				color;
}						t_square;

typedef struct			s_sqvar
{
	double				denom;
	double				nom;
	double				t;
	double				len;
	double				cosin;
	t_vec				d;
	t_vec				up;
	t_vec				axis;
}						t_sqvar;

typedef struct			s_cylinder
{
	t_vec				pos;
	t_vec				normal_vec;
	double				diameter;
	double				height;
	t_rgb				color;
	t_vec				top;
	t_vec				bot;
}						t_cylinder;

typedef struct			s_cyvar
{
	double				t;
	double				t1;
	double				t2;
	double				r2;
	double				a;
	double				b;
	double				c;
	t_vec				hc;
	t_vec				v;
	t_vec				w;
	t_vec				h;
	t_vec				p;
}						t_cyvar;

typedef struct			s_disk
{
	double				denom;
	double				nom;
	double				t;
	double				d2;
}						t_disk;

typedef struct			s_intersect_cy
{
	int					i;
	int					flag;
	t_list				*cylinders;
	t_cylinder			*cylinder;
}						t_intersect_cy;

typedef struct			s_triangle
{
	t_vec				p1;
	t_vec				p2;
	t_vec				p3;
	t_rgb				color;
	t_vec				normal_vec;
}						t_triangle;

typedef struct			s_rt_info
{
	int					cam_num;
	double				f;
	char				*initial[14];
	char				*type;
	t_area				resolution;
	t_am_light			al;
	t_list				*camera;
	t_list				*light;
	t_list				*sphere;
	t_list				*plane;
	t_list				*square;
	t_list				*cylinder;
	t_list				*triangle;
	t_list				*cone;
}						t_rt_info;

typedef struct			s_ray
{
	t_vec				orig;
	t_vec				dir;
	double				t;
}						t_ray;

typedef struct			s_hit
{
	t_vec				pos;
	t_vec				normal_vec;
	double				dist;
}						t_hit;
#endif
