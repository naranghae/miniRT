/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 16:08:24 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		sq_six(t_cube *cu)
{
	cu->x_m = ft_vec_create(cu->pos.x - cu->size, cu->pos.y, cu->pos.z);
	cu->x_p = ft_vec_create(cu->pos.x + cu->size, cu->pos.y, cu->pos.z);
	cu->y_m = ft_vec_create(cu->pos.x, cu->pos.y - cu->size, cu->pos.z);
	cu->y_p = ft_vec_create(cu->pos.x, cu->pos.y + cu->size, cu->pos.z);
	cu->z_m = ft_vec_create(cu->pos.x, cu->pos.y, cu->pos.z - cu->size);
	cu->z_p = ft_vec_create(cu->pos.x, cu->pos.y, cu->pos.z + cu->size);
}

void		cube_sq(t_rt_info *info, t_vec pos, t_vec normal_vec, t_cube cu)
{
	t_square *sq;

	if (!(sq = (t_square *)malloc(sizeof(*sq))))
		ft_error(MALLOC_FAIL);
	sq->center = pos;
	sq->normal_vec = normal_vec;
	sq->color = cu.color;
	sq->side_size = cu.size;
	ft_lstadd_front(&(info->square), ft_lstnew(sq));
}

void		set_cube(t_rt_info *info, char **line)
{
	t_cube cu;

	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		cu.pos = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line))
		cu.size = ft_rt_atod(line) * 0.5;
	next_thing(line);
	if (ft_isdigit(**line))
		cu.color = parse_rgb(line);
	sq_six(&cu);
	cube_sq(info, cu.x_m, ft_vec_create(-1, 0, 0), cu);
	cube_sq(info, cu.x_p, ft_vec_create(1, 0, 0), cu);
	cube_sq(info, cu.y_m, ft_vec_create(0, -1, 0), cu);
	cube_sq(info, cu.y_p, ft_vec_create(0, 1, 0), cu);
	cube_sq(info, cu.z_m, ft_vec_create(0, 0, -1), cu);
	cube_sq(info, cu.z_p, ft_vec_create(0, 0, 1), cu);
}
