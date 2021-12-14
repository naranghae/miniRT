/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 16:54:13 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			intersect_cone(t_ray ray, t_cone cone, t_hit *hit)
{
	t_covar var;

	cone_calc(&var, cone, ray);
	if (!co_discriminant(ft_vec_create(var.a, var.b, var.c), &var.t1, &var.t2))
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
	if (!co_boundary(ray, cone, var.t))
		return (0);
	hit->dist = var.t;
	hit->pos = ft_ray_at(ray, hit->dist);
	hit->normal_vec = get_co_normal(hit->pos, cone);
	hit->pos = ft_vec_add(hit->pos, ft_vec_multi_double(hit->normal_vec,
		EPSILON));
	return (1);
}

void		ray_cone(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_list		*cones;
	t_cone		*cone;
	t_cylinder	cy;

	cones = info->cone;
	while (cones->next)
	{
		cone = (t_cone *)(cones->content);
		if (intersect_cone(ray, *cone, hit))
		{
			*object = cone;
			ft_memcpy(info->type, "co\0", 3);
		}
		cy.normal_vec = cone->normal_vec;
		cy.pos = cone->pos;
		cy.diameter = cone->r;
		if (intersect_disk(ray, cy, hit, cy.pos))
		{
			*object = cone;
			ft_memcpy(info->type, "co\0", 3);
		}
		cones = cones->next;
	}
}

void		set_cone(t_rt_info *info, char **line)
{
	t_cone	*cone;

	if (!(cone = (t_cone *)malloc(sizeof(*cone))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		cone->pos = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line))
		cone->r = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		cone->height = ft_rt_atod(line);
	next_thing(line);
	if (ft_isdigit(**line))
		cone->color = parse_rgb(line);
	cone->normal_vec = ft_vec_create(0, 1, 0);
	cone->h = ft_vec_add(cone->pos,
		ft_vec_multi_double(cone->normal_vec, cone->height));
	ft_lstadd_front(&(info->cone), ft_lstnew(cone));
}
