/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 16:53:16 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			co_discriminant(t_vec vec, double *t1, double *t2)
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
		if (*t1 > *t2)
			ft_swap(t1, t2);
	}
	return (1);
}

int			co_boundary(t_ray ray, t_cone co, double t)
{
	t_vec	p;
	t_vec	cp;

	p = ft_ray_at(ray, t);
	cp = ft_vec_sub(co.pos, p);
	if (0 < ft_vec_dot(cp, co.normal_vec) ||
		ft_vec_dot(cp, co.normal_vec) < -co.height)
		return (0);
	return (1);
}

t_vec		get_co_normal(t_vec pos, t_cone co)
{
	t_vec	tmp;
	t_vec	normal;

	tmp = ft_vec_sub(pos, co.pos);
	normal = ft_vec_normalize(ft_vec_sub(tmp,
	ft_vec_multi_double(co.normal_vec, ft_vec_dot(co.normal_vec, tmp))));
	return (normal);
}

void		cone_calc(t_covar *var, t_cone cone, t_ray ray)
{
	var->h_hat = ft_vec_normalize(ft_vec_sub(cone.pos, cone.h));
	var->v = ray.dir;
	var->w = ft_vec_sub(ray.orig, cone.h);
	var->m = pow(cone.r, 2.0) / pow(cone.height, 2.0);
	var->a = ft_dot_mine(var->v) - (var->m + 1) *
		pow(ft_vec_dot(var->v, var->h_hat), 2.0);
	var->b = (ft_vec_dot(var->v, var->w) - (var->m + 1) *
	(ft_vec_dot(var->v, var->h_hat) * ft_vec_dot(var->w, var->h_hat))) * 2;
	var->c = ft_dot_mine(var->w) - (var->m + 1) *
		pow(ft_vec_dot(var->w, var->h_hat), 2.0);
}
