/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 16:22:17 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		intersect_plane(t_ray ray, t_plane plane, t_hit *hit)
{
	double	denom;
	double	nom;
	double	t;

	denom = ft_vec_dot(plane.normal_vec, ray.dir);
	nom = ft_vec_dot(ft_vec_sub(ray.orig, plane.pos), plane.normal_vec);
	if (denom > 1e-6)
	{
		t = -nom / denom;
		if (t > EPSILON && t < hit->dist)
		{
			hit->dist = t;
			hit->normal_vec = plane.normal_vec;
			hit->pos = ft_ray_at(ray, t);
			hit->pos = ft_vec_add(hit->pos,
				ft_vec_multi_double(hit->normal_vec, EPSILON));
			return (t);
		}
	}
	return (0);
}

void	ray_plane(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_list		*planes;
	t_plane		*plane;

	planes = info->plane;
	while (planes->next)
	{
		plane = (t_plane *)(planes->content);
		if (intersect_plane(ray, *plane, hit))
		{
			*object = plane;
			ft_memcpy(info->type, "pl\0", 3);
		}
		planes = planes->next;
	}
}
