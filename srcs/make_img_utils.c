/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 16:54:42 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		init_licolor(t_livar *var)
{
	var->diff_spec = itor(0, 0, 0);
	var->light_color = itor(0, 0, 0);
	var->specular_color = itor(0, 0, 0);
	var->diffuse_color = itor(0, 0, 0);
}

void		init_resol(t_mkvar *var, t_rt_info *info, t_camera *camera)
{
	var->color = itor(0, 0, 0);
	var->object = NULL;
	var->hit = NULL;
	var->ray = create_ray(camera, info, var->pixel);
	var->hit = ray_object(var->ray, info, &(var->object));
}

void		light_check(t_livar *var, t_ray ray, t_rt_info *info, t_hit *hit)
{
	var->object = NULL;
	var->light = (t_light *)(var->lights->content);
	var->v = ft_vec_sub(ray.orig, hit->pos);
	var->to_light = new_ray(hit->pos, ft_vec_sub(var->light->light_point,
	hit->pos));
	var->r = vec_reflect(ft_vec_sub(hit->pos, var->to_light.dir),
	hit->normal_vec);
	var->hit_object = ray_object(var->to_light, info, &(var->object));
}

void		light_calc(t_livar *var, t_hit *hit)
{
	var->diffuse = ft_max(ft_vec_dot(hit->normal_vec,
	ft_vec_normalize(var->to_light.dir)), 0.0);
	var->diffuse_color = rgb_multi_double(var->light->color, var->diffuse);
	var->specular = ft_max(pow(ft_vec_dot(ft_vec_normalize(var->v),
	ft_vec_normalize(var->r)), 150.0), 0.0);
	var->specular_color = rgb_multi_double(var->light->color, var->specular);
	var->light_color = add_rgb(add_rgb(var->diffuse_color,
	var->specular_color), var->light_color);
	var->diff_spec = rgb_multi_double(add_rgb(var->diff_spec,
	var->light_color), ALBEDO);
}

void		my_mlx_pixel_put(t_imgs *data, t_area pixel, int color)
{
	char *dst;

	dst = data->addr + (pixel.h * data->size_line +\
			pixel.w * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
