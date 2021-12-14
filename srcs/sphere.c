/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/11 12:00:14 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			sp_quadratic_equation(t_vec vec, double *t1, double *t2)
{
	double	t;
	double	discriminant;

	discriminant = vec.y * vec.y - (4 * vec.x * vec.z);
	if (discriminant < 0)
		return (0);
	else if (discriminant == 0)
	{
		*t1 = (-vec.y) / (2 * vec.x);
		*t2 = (-vec.y) / (2 * vec.x);
	}
	else
	{
		t = (vec.y > 0) ? -0.5 * (vec.y + sqrt(discriminant)) :
			-0.5 * (vec.y - sqrt(discriminant));
		*t1 = t / vec.x;
		*t2 = vec.z / t;
	}
	if (*t1 > *t2)
		ft_swap(t1, t2);
	return (1);
}

void		init_spvar(t_spvar *var, t_ray ray, t_sphere sp)
{
	var->vec = ft_vec_create(ray.orig.x - sp.center.x,
	ray.orig.y - sp.center.y,
	ray.orig.z - sp.center.z);
	var->a = ft_dot_mine(ray.dir);
	var->b = 2.0 * ft_vec_dot(var->vec, ray.dir);
	var->c = ft_dot_mine(var->vec) - (sp.radius * sp.radius);
}

int			intersect_sphere(t_ray ray, t_sphere sp, t_hit *hit)
{
	t_spvar var;

	init_spvar(&var, ray, sp);
	if (!sp_quadratic_equation(ft_vec_create(var.a, var.b, var.c), &var.t1,
		&var.t2))
		return (0);
	if ((var.t1 < 0 && var.t2 < 0) ||
		(var.t1 > hit->dist && var.t2 > hit->dist))
		return (0);
	if (var.t2 < 0)
		return (0);
	if (var.t1 > 0)
		var.t = var.t1;
	else
		var.t = var.t2;
	hit->dist = var.t;
	hit->pos = ft_ray_at(ray, hit->dist);
	hit->normal_vec = ft_vec_normalize(ft_vec_sub(hit->pos, sp.center));
	hit->pos = ft_vec_add(hit->pos, ft_vec_multi_double(hit->normal_vec,
		EPSILON));
	return (1);
}

void		ray_sphere(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_list		*spheres;
	t_sphere	*sp;

	spheres = info->sphere;
	while (spheres->next)
	{
		sp = (t_sphere *)(spheres->content);
		if (intersect_sphere(ray, *sp, hit))
		{
			*object = sp;
			ft_memcpy(info->type, "sp\0", 3);
		}
		spheres = spheres->next;
	}
}
