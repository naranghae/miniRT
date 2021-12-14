/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 19:28:01 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	next_element(char **str)
{
	while (ft_isdigit(**str) || **str == '-' || **str == '.' || **str == ',')
		(*str)++;
}

void	next_space(char **str)
{
	while (is_space(**str))
		(*str)++;
}

void	next_thing(char **str)
{
	next_element(str);
	next_space(str);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == ',' || c == '\n');
}

void	line_parsing(t_rt_info *info, char *line)
{
	char	*line_p;

	line_p = line;
	ft_parsing(info, &line);
	line = NULL;
	free(line_p);
}
