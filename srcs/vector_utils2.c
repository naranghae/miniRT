/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:14:15 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double			ft_vec_dot(t_vec u, t_vec v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

t_vec			ft_vec_cross(t_vec u, t_vec v)
{
	return (ft_vec_create(
		u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x));
}

t_vec			ft_vec_minus(t_vec u)
{
	return (ft_vec_create(-1 * u.x, -1 * u.y, -1 * u.z));
}

double			ft_vec_len(t_vec new_vec)
{
	return (sqrt(ft_vec_len_sqrt(new_vec)));
}

double			ft_vec_dist(t_vec u, t_vec v)
{
	t_vec	dist_vec;

	dist_vec.x = v.x - u.x;
	dist_vec.y = v.y - u.y;
	dist_vec.z = v.z - u.z;
	return (ft_vec_len(dist_vec));
}
