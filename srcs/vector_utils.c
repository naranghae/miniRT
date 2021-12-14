/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:14:17 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec			ft_vec_create(double x, double y, double z)
{
	t_vec	new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_vec			ft_vec_add(t_vec u, t_vec v)
{
	return (ft_vec_create(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vec			ft_vec_sub(t_vec u, t_vec v)
{
	return (ft_vec_create(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vec			ft_vec_multi_double(t_vec v, double t)
{
	return (ft_vec_create(v.x * t, v.y * t, v.z * t));
}

t_vec			ft_vec_div_double(t_vec v, double t)
{
	return (ft_vec_create(v.x / t, v.y / t, v.z / t));
}
