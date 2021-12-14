/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/11 14:07:24 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec		ft_ray_at(t_ray ray, double t)
{
	return (ft_vec_create(ray.orig.x + t * ray.dir.x,
	ray.orig.y + t * ray.dir.y,
	ray.orig.z + t * ray.dir.z));
}

double		vec_size(t_vec v)
{
	return (sqrt(ft_dot_mine(v)));
}

double		cosval(t_vec a, t_vec b)
{
	return (ft_vec_dot(a, b) / (vec_size(a) * vec_size(b)));
}
