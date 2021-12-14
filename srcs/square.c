/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 14:37:31 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			sq_outside(t_ray ray, t_square sq, t_sqvar *var)
{
	var->d = ft_vec_sub(ft_ray_at(ray, var->t), sq.center);
	var->up = ft_vec_create(0, 1, 0);
	if (sq.normal_vec.y != 0 && (sq.normal_vec.x == 0 && sq.normal_vec.z == 0))
		var->up = ft_vec_create(0, 0, 1);
	var->axis = ft_vec_cross(var->up, sq.normal_vec);
	var->cosin = fabs(cosval(var->axis, var->d));
	if (var->cosin < sqrt(2) / 2)
		var->cosin = cos((MINI_PI / 2) - acos(var->cosin));
	var->len = sq.side_size / var->cosin;
	if (vec_size(var->d) > var->len)
		return (0);
	return (1);
}

int			intersect_square(t_ray ray, t_square sq, t_hit *hit)
{
	t_sqvar	var;

	var.denom = ft_vec_dot(sq.normal_vec, ray.dir);
	var.nom = ft_vec_dot(ft_vec_sub(ray.orig, sq.center), sq.normal_vec);
	if (var.denom == 0)
		return (0);
	var.t = -var.nom / var.denom;
	if (!sq_outside(ray, sq, &var))
		return (0);
	if (var.t > EPSILON && var.t < hit->dist)
	{
		hit->dist = var.t;
		hit->pos = ft_ray_at(ray, var.t);
		hit->normal_vec = sq.normal_vec;
		hit->pos = ft_vec_add(hit->pos,
			ft_vec_multi_double(sq.normal_vec, EPSILON));
		return (1);
	}
	return (0);
}

void		ray_square(t_ray ray, t_rt_info *info, t_hit *hit, void **object)
{
	t_list		*squares;
	t_square	*square;

	squares = info->square;
	while (squares->next)
	{
		square = (t_square *)(squares->content);
		if (intersect_square(ray, *square, hit))
		{
			*object = square;
			ft_memcpy(info->type, "sq\0", 3);
		}
		squares = squares->next;
	}
}
