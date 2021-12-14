/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 21:27:59 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb		itor(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_vec		parse_vec(char **str)
{
	t_vec	vec;

	vec.x = ft_rt_atod(str);
	next_space(str);
	vec.y = ft_rt_atod(str);
	next_space(str);
	vec.z = ft_rt_atod(str);
	return (vec);
}

t_rgb		parse_rgb(char **str)
{
	t_rgb	rgb;

	rgb.r = ft_rt_atoi(str);
	next_space(str);
	rgb.g = ft_rt_atod(str);
	next_space(str);
	rgb.b = ft_rt_atod(str);
	return (rgb);
}
