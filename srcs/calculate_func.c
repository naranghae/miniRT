/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 16:58:00 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	rgb_value(t_rgb *rgb)
{
	rgb->r = rgb->r > 255 ? 255 : rgb->r;
	rgb->g = rgb->g > 255 ? 255 : rgb->g;
	rgb->b = rgb->b > 255 ? 255 : rgb->b;
}

double	get_radian(double degree)
{
	return (degree * MINI_PI / 180.0);
}

void	ft_swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

double	ft_max(double a, double b)
{
	double max;

	max = (a) > (b) ? (a) : (b);
	return (max);
}
