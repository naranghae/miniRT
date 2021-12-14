/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/11 11:59:59 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double			ft_vec_len_sqrt(t_vec new_vec)
{
	return (pow(new_vec.x, 2) + pow(new_vec.y, 2) + pow(new_vec.z, 2));
}

t_vec			ft_vec_normalize(t_vec v)
{
	return (ft_vec_div_double(v, ft_vec_len(v)));
}

t_vec			vec_reflect(t_vec v, t_vec n)
{
	t_vec	tmp;
	t_vec	refl;

	tmp = ft_vec_multi_double(n, 2 * ft_vec_dot(v, n));
	refl = ft_vec_sub(v, tmp);
	return (refl);
}

double			ft_dot_mine(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

t_vec			select_normal(t_ray ray, t_vec nv)
{
	double	res;
	t_vec	tmp;

	res = ft_vec_dot(ray.dir, nv);
	if (res < 0)
		return (nv);
	tmp = ft_vec_minus(nv);
	return (tmp);
}
