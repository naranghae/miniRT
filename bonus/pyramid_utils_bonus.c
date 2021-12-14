/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 17:05:52 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		ob_five(t_pyramid *py)
{
	py->p1 = ft_vec_create(py->pos.x - py->size, py->pos.y,
			py->pos.z - py->size);
	py->p2 = ft_vec_create(py->pos.x - py->size, py->pos.y,
			py->pos.z + py->size);
	py->p3 = ft_vec_create(py->pos.x + py->size, py->pos.y,
			py->pos.z + py->size);
	py->p4 = ft_vec_create(py->pos.x + py->size, py->pos.y,
			py->pos.z - py->size);
	py->top = ft_vec_create(py->pos.x, py->pos.y + py->size + py->size / 2,
				py->pos.z);
}

t_pyvar		py_dot_create(t_vec a, t_vec b, t_vec c)
{
	t_pyvar		py_dot;

	py_dot.p1 = a;
	py_dot.p2 = b;
	py_dot.p3 = c;
	return (py_dot);
}
