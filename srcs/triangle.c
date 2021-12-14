/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 15:20:30 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		tr_except(t_vec a, t_vec b, t_vec c, t_vec hit)
{
	t_vec	ba;
	t_vec	ca;
	t_vec	ha;

	ba = ft_vec_sub(b, a);
	ca = ft_vec_sub(c, a);
	ha = ft_vec_sub(hit, a);
	if (ft_vec_dot(ft_vec_cross(ba, ca), ft_vec_cross(ha, ca)) < 0)
		return (0);
	return (1);
}

int		tr_outside(t_ray ray, t_triangle tr, double t)
{
	t_vec	hitray;

	hitray = ft_ray_at(ray, t);
	if (!tr_except(tr.p1, tr.p2, tr.p3, hitray))
		return (0);
	if (!tr_except(tr.p2, tr.p3, tr.p1, hitray))
		return (0);
	if (!tr_except(tr.p3, tr.p1, tr.p2, hitray))
		return (0);
	return (1);
}

int		intersect_triangle(t_ray ray, t_triangle tr, t_hit *hit)
{
	double		denom;
	double		nom;
	double		t;

	denom = ft_vec_dot(tr.normal_vec, ray.dir);
	nom = ft_vec_dot(ft_vec_sub(ray.orig, tr.p1), tr.normal_vec);
	if (denom == 0)
		return (0);
	t = -nom / denom;
	if (!tr_outside(ray, tr, t))
		return (0);
	if (t > EPSILON && t < hit->dist)
	{
		hit->dist = t;
		hit->pos = ft_ray_at(ray, hit->dist);
		hit->normal_vec = tr.normal_vec;
		hit->pos = ft_vec_add(hit->pos,
			ft_vec_multi_double(hit->normal_vec, EPSILON));
		return (1);
	}
	return (0);
}

void	ray_triangle(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_list			*tris;
	t_triangle		*tri;

	tris = info->triangle;
	while (tris->next)
	{
		tri = (t_triangle *)(tris->content);
		if (intersect_triangle(ray, *tri, hit))
		{
			*object = tri;
			ft_memcpy(info->type, "tr\0", 3);
		}
		tris = tris->next;
	}
}
