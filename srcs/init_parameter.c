/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 21:28:15 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		*init_info(t_rt_info *info)
{
	if (!(info->type = malloc(sizeof(char) * 3)))
		ft_error(MALLOC_FAIL);
	ft_bzero(info->type, 3);
	info->resolution.w = 0;
	info->resolution.h = 0;
	info->f = 0;
	info->al.ratio = 0;
	info->al.color.r = 0;
	info->al.color.g = 0;
	info->al.color.b = 0;
	info->camera = ft_lstnew(NULL);
	info->light = ft_lstnew(NULL);
	info->sphere = ft_lstnew(NULL);
	info->plane = ft_lstnew(NULL);
	info->square = ft_lstnew(NULL);
	info->cylinder = ft_lstnew(NULL);
	info->triangle = ft_lstnew(NULL);
	info->cone = ft_lstnew(NULL);
	return (info);
}

void		set_resolution(t_rt_info *info, char **line)
{
	int		*num;
	int		i;

	i = 0;
	if (!(num = (int *)malloc(sizeof(int) * 3)))
		ft_error(MALLOC_FAIL);
	next_space(line);
	while (**line)
	{
		if (ft_isdigit(**line))
		{
			num[i] = ft_rt_atoi(line);
			i++;
		}
		(*line)++;
	}
	num[i] = '\0';
	info->resolution.w = num[0];
	info->resolution.h = num[1];
	free(num);
}

void		set_ambient_lighting(t_rt_info *info, char **line)
{
	next_space(line);
	if (ft_isdigit(**line))
		info->al.ratio = ft_rt_atod(line);
	next_space(line);
	if (ft_isdigit(**line))
		info->al.color = rgb_multi_double(parse_rgb(line), info->al.ratio);
}

void		set_camera(t_rt_info *info, char **line)
{
	t_camera	*camera;
	static int	i;

	if (!(camera = (t_camera *)malloc(sizeof(*camera))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		camera->view_point = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line) || **line == '-')
		camera->normal_vec = ft_vec_normalize(parse_vec(line));
	next_thing(line);
	if (ft_isdigit(**line))
		camera->fov = ft_rt_atoi(line);
	info->cam_num = ++i;
	ft_lstadd_front(&(info->camera), ft_lstnew(camera));
}

void		set_light(t_rt_info *info, char **line)
{
	t_light *light;

	if (!(light = (t_light *)malloc(sizeof(*light))))
		ft_error(MALLOC_FAIL);
	next_space(line);
	if (ft_isdigit(**line) || **line == '-')
		light->light_point = parse_vec(line);
	next_thing(line);
	if (ft_isdigit(**line))
		light->ratio = ft_rt_atod(line);
	next_thing(line);
	if (ft_isdigit(**line))
		light->color = rgb_multi_double(parse_rgb(line), light->ratio);
	ft_lstadd_front(&(info->light), ft_lstnew(light));
}
