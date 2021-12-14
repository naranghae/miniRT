/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 17:01:59 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		pyramid_sq(t_rt_info *info, t_pyramid py)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(*sq))))
		ft_error(MALLOC_FAIL);
	sq->center = py.pos;
	sq->normal_vec = ft_vec_create(0, -1, 0);
	sq->color = py.color;
	sq->side_size = py.size;
	ft_lstadd_front(&(info->square), ft_lstnew(sq));
}

void		pyramid_tr(t_rt_info *info, t_pyvar point, t_rgb color)
{
	t_triangle	*tri;

	if (!(tri = (t_triangle *)malloc(sizeof(*tri))))
		ft_error(MALLOC_FAIL);
	tri->p1 = point.p1;
	tri->p2 = point.p2;
	tri->p3 = point.p3;
	tri->color = color;
	tri->normal_vec = ft_vec_normalize(ft_vec_cross(
		ft_vec_sub(tri->p2, tri->p1), ft_vec_sub(tri->p3, tri->p1)));
	ft_lstadd_front(&(info->triangle), ft_lstnew(tri));
}

void		set_pyramid(t_rt_info *info, char **line)
{
	t_pyramid		py;

	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		py.pos = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line))
		py.size = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		py.color = parse_rgb(line);
	ob_five(&py);
	pyramid_tr(info, py_dot_create(py.p1, py.top, py.p2), py.color);
	pyramid_tr(info, py_dot_create(py.p2, py.top, py.p3), py.color);
	pyramid_tr(info, py_dot_create(py.p3, py.top, py.p4), py.color);
	pyramid_tr(info, py_dot_create(py.p4, py.top, py.p1), py.color);
	pyramid_sq(info, py);
}
