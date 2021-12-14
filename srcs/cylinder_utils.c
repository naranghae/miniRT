/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 11:35:11 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	get_cy_normal(t_vec pos, t_cylinder cy)
{
	t_vec	tmp;
	t_vec	normal;

	tmp = ft_vec_sub(pos, cy.pos);
	normal = ft_vec_normalize(ft_vec_sub(tmp,
	ft_vec_multi_double(cy.normal_vec, ft_vec_dot(cy.normal_vec, tmp))));
	return (normal);
}

int		cy_boundary(t_ray ray, t_cylinder cy, t_cyvar var)
{
	double	len;

	var.p = ft_ray_at(ray, var.t);
	len = sqrt(pow(cy.diameter, 2.0) + pow(cy.height, 2.0));
	if (ft_vec_dist(cy.pos, var.p) > len)
		return (0);
	return (1);
}

void	t_select(double *t1, double *t2, int i)
{
	if (i == 1)
	{
		if (*t1 > *t2)
			ft_swap(t1, t2);
	}
	else
	{
		if (*t1 < *t2)
			ft_swap(t1, t2);
	}
}

double	intersect_check(t_cyvar var, double *t1, double *t2, int i)
{
	double	root;
	double	t;

	root = (var.b * var.b) - (4 * var.a * var.c);
	if (root < 0)
		return (0);
	if (root > 0)
	{
		t = (var.b > 0) ? -0.5 * (var.b + sqrt(root)) :
			-0.5 * (var.b - sqrt(root));
		*t1 = t / var.a;
		*t2 = var.c / t;
		t_select(t1, t2, i);
	}
	else if (root == 0)
	{
		if (fabs(ft_vec_dot(var.v, var.h)) != 1)
		{
			*t1 = -var.b / (2 * var.a);
			*t2 = -var.b / (2 * var.a);
		}
	}
	return (1);
}

double	cy_calc(t_cyvar var, t_hit *hit, int i)
{
	double t;

	var.a = ft_dot_mine(var.v) - pow(ft_vec_dot(var.v, var.h), 2);
	var.b = (ft_vec_dot(var.v, var.w) - (ft_vec_dot(var.v, var.h) *
	ft_vec_dot(var.w, var.h))) * 2;
	var.c = ft_dot_mine(var.w) - pow(ft_vec_dot(var.w, var.h), 2) - var.r2;
	if (!(intersect_check(var, &var.t1, &var.t2, i)))
		return (0);
	if ((var.t1 < 0 && var.t2 < 0) ||
	(var.t1 > hit->dist && var.t2 > hit->dist))
		return (0);
	if (var.t2 < 0)
		return (0);
	if (var.t1 > 0)
		t = var.t1;
	else
		t = var.t2;
	return (t);
}
