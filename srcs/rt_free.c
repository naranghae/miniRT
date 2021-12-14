/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 12:43:04 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		lst_free(t_list **head)
{
	t_list	*prev;
	t_list	*rm;

	prev = NULL;
	rm = *head;
	while (rm)
	{
		prev = rm;
		rm = rm->next;
		free(prev);
	}
	*head = NULL;
	return (0);
}

int		cam_free(t_list *lst_cam)
{
	t_camera *cam;

	while (lst_cam->next)
	{
		cam = (t_camera *)(lst_cam->content);
		free(cam);
		lst_cam = lst_cam->next;
	}
	lst_free(&lst_cam);
	return (0);
}

int		li_free(t_list *lst_li)
{
	t_light *li;

	while (lst_li->next)
	{
		li = (t_light *)(lst_li->content);
		free(li);
		lst_li = lst_li->next;
	}
	lst_free(&lst_li);
	return (0);
}

int		rt_free(t_rt_info *info)
{
	free(info->type);
	cam_free(info->camera);
	li_free(info->light);
	sp_free(info->sphere);
	pl_free(info->plane);
	sq_free(info->square);
	tr_free(info->triangle);
	cy_free(info->cylinder);
	co_free(info->cone);
	return (0);
}
