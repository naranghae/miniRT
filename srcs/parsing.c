/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 21:25:58 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char			*ft_split_type(char **line)
{
	char	*type;
	int		i;

	i = 0;
	if (!(type = (char *)malloc(sizeof(char) * 3)))
		ft_error(MISMATCH_TYPE);
	while (**line)
	{
		if (ft_isalpha(**line) > 0)
			type[i] = **line;
		(*line)++;
		i++;
		if (is_space(**line))
			break ;
	}
	type[i] = '\0';
	return (type);
}

void			object(t_rt_info *info, char **line, char *type)
{
	if (!ft_strncmp(type, "sp", 3))
		set_sphere(info, line);
	else if (!ft_strncmp(type, "pl", 3))
		set_plane(info, line);
	else if (!ft_strncmp(type, "sq", 3))
		set_square(info, line);
	else if (!ft_strncmp(type, "tr", 3))
		set_triangle(info, line);
	else if (!ft_strncmp(type, "cy", 3))
		set_cylinder(info, line);
	else if (!ft_strncmp(type, "co", 3))
		set_cone(info, line);
	else if (!ft_strncmp(type, "cu", 3))
		set_cube(info, line);
	else if (!ft_strncmp(type, "py", 3))
		set_pyramid(info, line);
}

void			ft_parsing(t_rt_info *info, char **line)
{
	char	*type;

	type = ft_split_type(line);
	if (!ft_strncmp(type, "R", 2))
		set_resolution(info, line);
	else if (!ft_strncmp(type, "A", 2))
		set_ambient_lighting(info, line);
	else if (!ft_strncmp(type, "F", 2))
		filter_check(info, line);
	else if (!ft_strncmp(type, "c", 2))
		set_camera(info, line);
	else if (!ft_strncmp(type, "l", 2))
		set_light(info, line);
	object(info, line, type);
	free(type);
}

t_rt_info		*rt_save(int fd)
{
	t_rt_info		*info;
	char			*line;
	int				chk;

	if (!(info = (t_rt_info *)malloc(sizeof(*info))))
		ft_error(MALLOC_FAIL);
	if (!(init_info(info)))
		ft_error(INIT_RTINFO_FAIL);
	line = NULL;
	while ((chk = get_next_line(fd, &line)) > 0)
		line_parsing(info, line);
	line_parsing(info, line);
	return (info);
}

t_rt_info		*put_info(char **av)
{
	int			fd;
	t_rt_info	*info;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error(READ_FAIL);
	if (!(info = rt_save(fd)))
		ft_error(PARSING_ERROR);
	if (close(fd) == -1)
		ft_error(CLOSE_ERROR);
	return (info);
}
