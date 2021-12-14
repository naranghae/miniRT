/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_sepia_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 16:53:53 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		filter_check(t_rt_info *info, char **line)
{
	next_space(line);
	if (!ft_strncmp(*line, "s", 2))
		info->f = 1;
}

void		sepia_color(t_rgb *rgb)
{
	rgb->r = rgb->r * 0.393 + rgb->g * 0.769 + rgb->b * 0.189;
	rgb->g = rgb->r * 0.349 + rgb->g * 0.686 + rgb->b * 0.168;
	rgb->b = rgb->r * 0.272 + rgb->g * 0.534 + rgb->b * 0.131;
}
