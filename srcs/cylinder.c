/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 14:10:00 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		intersect_disk(t_ray ray, t_cylinder cy, t_hit *hit, t_vec disk_pos)
{
	t_disk	var;

	var.denom = ft_vec_dot(cy.normal_vec, ray.dir);
	var.nom = ft_vec_dot(ft_vec_sub(ray.orig, disk_pos), cy.normal_vec);
	if (var.denom == 0)
		return (0);
	var.t = -var.nom / var.denom;
	var.d2 = ft_dot_mine(ft_vec_sub(ft_ray_at(ray, var.t), disk_pos));
	if (sqrtf(var.d2) > cy.diameter)
		return (0);
	if (var.t > EPSILON && var.t < hit->dist)
	{
		hit->dist = var.t;
		hit->pos = ft_ray_at(ray, hit->dist);
		hit->normal_vec = cy.normal_vec;
		hit->pos = ft_vec_add(hit->pos,
			ft_vec_multi_double(cy.normal_vec, EPSILON));
		return (1);
	}
	return (0);
}

void	cy_basic_value(t_cyvar *var, t_cylinder cy, t_ray ray)
{
	var->r2 = cy.diameter * cy.diameter;
	var->hc = ft_vec_sub(cy.top, cy.bot);
	var->h = ft_vec_normalize(var->hc);
	var->w = ft_vec_sub(ray.orig, cy.bot);
	var->v = ray.dir;
}

int		intersect_cylinder(t_ray ray, t_cylinder cy, t_hit *hit, int i)
{
	t_cyvar	var;

	cy_basic_value(&var, cy, ray);
	if (!(var.t = cy_calc(var, hit, i)))
		return (0);
	if (!cy_boundary(ray, cy, var))
		return (0);
	hit->dist = var.t;
	hit->pos = ft_ray_at(ray, var.t);
	hit->normal_vec = get_cy_normal(hit->pos, cy);
	hit->pos = ft_vec_add(hit->pos, ft_vec_multi_double(hit->normal_vec,
		EPSILON));
	return (1);
}

void	init_flag(t_intersect_cy *var)
{
	var->i = 2;
	var->flag = 1;
}

void	ray_cylinder(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_intersect_cy var;

	var.cylinders = info->cylinder;
	while (var.cylinders->next)
	{
		init_flag(&var);
		var.cylinder = (t_cylinder *)(var.cylinders->content);
		while (var.i--)
		{
			if (intersect_cylinder(ray, *var.cylinder, hit, var.flag))
			{
				var.i = 0;
				*object = var.cylinder;
				ft_memcpy(info->type, "cy\0", 3);
			}
			if (intersect_disk(ray, *var.cylinder, hit, var.cylinder->top) ||
			intersect_disk(ray, *var.cylinder, hit, var.cylinder->bot))
			{
				*object = var.cylinder;
				ft_memcpy(info->type, "cy\0", 3);
			}
			var.flag = 0;
		}
		var.cylinders = var.cylinders->next;
	}
}
