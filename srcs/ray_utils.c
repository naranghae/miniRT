/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 16:54:12 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray		new_ray(t_vec orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	ray.t = INFINITY;
	return (ray);
}

t_vec		set_cam(double fov, t_area resolution, int y, int x)
{
	double	d_x;
	double	d_y;
	double	aspect_ratio;
	double	fov_coeff;

	fov_coeff = tan(get_radian(fov) * 0.5);
	aspect_ratio = (double)resolution.w / (double)resolution.h;
	d_x = (2 * (x + 0.5) / (double)resolution.w - 1)
					* aspect_ratio * fov_coeff;
	d_y = (1 - 2 * (y + 0.5) / (double)resolution.h)
					* fov_coeff;
	return (ft_vec_create(d_x, d_y, 1));
}

t_camvar	ft_look_at(t_vec orig, t_vec nv)
{
	t_vec		rdup;
	t_vec		horiz;
	t_vec		vup;
	t_camvar	var;

	rdup = ft_vec_create(0, 1, 0);
	if (nv.y != 0 && (nv.x == 0 && nv.z == 0))
		rdup = ft_vec_create(0, 0, 1);
	rdup = ft_vec_normalize(rdup);
	horiz = ft_vec_normalize(ft_vec_cross(rdup, nv));
	vup = ft_vec_normalize(ft_vec_cross(nv, horiz));
	var.rot[0] = ft_vec_create(horiz.x, vup.x, nv.x);
	var.rot[1] = ft_vec_create(horiz.y, vup.y, nv.y);
	var.rot[2] = ft_vec_create(horiz.z, vup.z, nv.z);
	var.rot[3] = ft_vec_create(orig.x, orig.y, orig.z);
	return (var);
}

t_vec		dir_calc(t_vec vec, t_camvar var)
{
	t_vec	v;

	v.x = ft_vec_dot(vec, var.rot[0]) + var.rot[3].x;
	v.y = ft_vec_dot(vec, var.rot[1]) + var.rot[3].y;
	v.z = ft_vec_dot(vec, var.rot[2]) + var.rot[3].z;
	return (v);
}

t_ray		create_ray(t_camera *camera, t_rt_info *info, t_area pixel)
{
	t_vec		vec_orig;
	t_vec		vec_dir;
	t_camvar	c2w;

	c2w = ft_look_at(camera->view_point, camera->normal_vec);
	vec_orig = dir_calc(ft_vec_create(0, 0, 0), c2w);
	vec_dir = set_cam(camera->fov, info->resolution, pixel.h, pixel.w);
	vec_dir = dir_calc(vec_dir, c2w);
	vec_dir = ft_vec_normalize(ft_vec_sub(vec_dir, vec_orig));
	return (new_ray(vec_orig, vec_dir));
}
