/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:15:26 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ELEMENT_H
# define PARSE_ELEMENT_H
# include "rt_info.h"

t_vec			set_vec(char *x, char *y, char *z);
t_vec			str_to_vec(char *str);
t_rgb			str_to_rgb(char *str);
t_rgb			ctor(char *r, char *g, char *b);
t_rgb			itor(int r, int g, int b);
t_vec			parse_vec(char **str);
t_rgb			parse_rgb(char **str);
#endif
