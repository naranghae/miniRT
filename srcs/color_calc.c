/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 17:13:50 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			rtoi(t_rgb rgb, double filter)
{
	rgb_value(&rgb);
	if (filter == 1)
	{
		sepia_color(&rgb);
		rgb_value(&rgb);
		return (rgb.r << 16 | rgb.g << 8 | rgb.b);
	}
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb		add_rgb(t_rgb rgb, t_rgb add)
{
	return (itor(rgb.r + add.r, rgb.g + add.g, rgb.b + add.b));
}

t_rgb		rgb_multi(t_rgb rgb, t_rgb multi)
{
	return (itor(rgb.r * (multi.r / 255.0), rgb.g * (multi.g / 255.0),
	rgb.b * (multi.b / 255.0)));
}

t_rgb		rgb_multi_double(t_rgb rgb, double multi)
{
	return (itor(rgb.r * multi, rgb.g * multi, rgb.b * multi));
}

t_rgb		get_color(char *type, void *object)
{
	if (!ft_strncmp(type, "sp", 2))
		return (((t_sphere *)object)->color);
	if (!ft_strncmp(type, "pl", 2))
		return (((t_plane *)object)->color);
	if (!ft_strncmp(type, "sq", 2))
		return (((t_square *)object)->color);
	if (!ft_strncmp(type, "cy", 2))
		return (((t_cylinder *)object)->color);
	if (!ft_strncmp(type, "tr", 2))
		return (((t_triangle *)object)->color);
	if (!ft_strncmp(type, "co", 2))
		return (((t_cone *)object)->color);
	return (itor(0, 0, 0));
}
