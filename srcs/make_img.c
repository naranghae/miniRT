/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 16:54:37 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_hit	*ray_object(t_ray ray, t_rt_info *info, void **object)
{
	t_hit *hit;

	if (!(hit = (t_hit *)malloc(sizeof(*hit))))
		ft_error(MALLOC_FAIL);
	hit->dist = INFINITY;
	ray_sphere(ray, info, hit, object);
	ray_plane(ray, info, hit, object);
	ray_square(ray, info, hit, object);
	ray_triangle(ray, info, hit, object);
	ray_cylinder(ray, info, hit, object);
	ray_cone(ray, info, hit, object);
	return (hit);
}

int		*show_light(t_ray ray, t_rt_info *info, t_hit *hit, t_rgb *color)
{
	t_livar var;

	init_licolor(&var);
	var.lights = info->light;
	while (var.lights->next)
	{
		light_check(&var, ray, info, hit);
		if (var.hit_object->dist >= ft_vec_dist(hit->pos,
			var.light->light_point))
			light_calc(&var, hit);
		free(var.hit_object);
		var.lights = var.lights->next;
	}
	*color = rgb_multi(add_rgb(info->al.color, var.diff_spec), *color);
	return (0);
}

void	make_img(t_imgs *img, t_rt_info *info, t_camera *camera)
{
	t_mkvar var;

	var.pixel.h = info->resolution.h;
	while (--var.pixel.h >= 0)
	{
		var.pixel.w = -1;
		while (++var.pixel.w < info->resolution.w)
		{
			init_resol(&var, info, camera);
			if (var.object)
			{
				var.color = get_color(info->type, var.object);
				if (ft_vec_dot(var.hit->normal_vec, var.ray.dir) >= 0.0)
					var.hit->normal_vec = ft_vec_minus(var.hit->normal_vec);
				show_light(var.ray, info, var.hit, &(var.color));
			}
			free(var.hit);
			my_mlx_pixel_put(img, var.pixel, rtoi(var.color, info->f));
		}
	}
}
