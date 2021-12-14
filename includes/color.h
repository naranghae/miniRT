/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/15 17:10:57 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "rt_info.h"

int			rtoi(t_rgb rgb, double filter);
t_rgb		add_rgb(t_rgb rgb, t_rgb add);
t_rgb		rgb_multi(t_rgb rgb, t_rgb multi);
t_rgb		rgb_multi_double(t_rgb rgb, double multi);
t_rgb		get_color(char *type, void *object);
void		rgb_value(t_rgb *rgb);
#endif
