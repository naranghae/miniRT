/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 10:54:22 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		set_sphere(t_rt_info *info, char **line)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(*sphere))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		sphere->center = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		sphere->radius = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		sphere->color = parse_rgb(line);
	ft_lstadd_front(&(info->sphere), ft_lstnew(sphere));
}

void		set_plane(t_rt_info *info, char **line)
{
	t_plane	*plane;

	if (!(plane = (t_plane *)malloc(sizeof(*plane))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		plane->pos = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		plane->normal_vec = ft_vec_normalize(parse_vec(line));
	next_thing(line);
	if (ft_isdigit(**line))
		plane->color = parse_rgb(line);
	ft_lstadd_front(&(info->plane), ft_lstnew(plane));
}

void		set_square(t_rt_info *info, char **line)
{
	t_square	*square;

	if (!(square = (t_square *)malloc(sizeof(*square))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		square->center = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		square->normal_vec = ft_vec_normalize(parse_vec(line));
	next_thing(line);
	if (ft_isdigit(**line))
		square->side_size = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		square->color = parse_rgb(line);
	ft_lstadd_front(&(info->square), ft_lstnew(square));
}

void		set_triangle(t_rt_info *info, char **line)
{
	t_triangle	*tri;

	if (!(tri = (t_triangle *)malloc(sizeof(*tri))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		tri->p1 = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		tri->p2 = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		tri->p3 = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line))
		tri->color = parse_rgb(line);
	tri->normal_vec = ft_vec_normalize(ft_vec_cross(
		ft_vec_sub(tri->p2, tri->p1), ft_vec_sub(tri->p3, tri->p1)));
	ft_lstadd_front(&(info->triangle), ft_lstnew(tri));
}

void		set_cylinder(t_rt_info *info, char **line)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(*cylinder))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		cylinder->pos = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		cylinder->normal_vec = ft_vec_normalize(parse_vec(line));
	next_thing(line);
	if (ft_isdigit(**line))
		cylinder->diameter = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		cylinder->height = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		cylinder->color = parse_rgb(line);
	cylinder->top = ft_vec_add(cylinder->pos,
		ft_vec_multi_double(cylinder->normal_vec, cylinder->height));
	cylinder->bot = ft_vec_sub(cylinder->pos,
		ft_vec_multi_double(cylinder->normal_vec, cylinder->height));
	ft_lstadd_front(&(info->cylinder), ft_lstnew(cylinder));
}
