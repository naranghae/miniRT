/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 12:42:13 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	cam_shift(t_data *data)
{
	t_imgs *lst_imgs;

	if (data->lst_imgs->next)
	{
		data->lst_imgs = data->lst_imgs->next;
		lst_imgs = data->lst_imgs->content;
		mlx_clear_window(data->mlx->mlx_p, data->mlx->win_p);
		mlx_put_image_to_window(data->mlx->mlx_p, data->mlx->win_p,
		lst_imgs->img, 0, 0);
	}
}

int		ft_key_press(int key, t_data *data)
{
	t_imgs	*lst_imgs;
	int		i;

	i = data->i;
	printf("pre_key: %d\n", key);
	if (key == ESC)
	{
		mlx_clear_window(data->mlx->mlx_p, data->mlx->win_p);
		mlx_destroy_window(data->mlx->mlx_p, data->mlx->win_p);
		while (i--)
		{
			lst_imgs = data->lst_imgs->content;
			mlx_destroy_image(data->mlx->mlx_p, lst_imgs->img);
			free(lst_imgs);
			data->lst_imgs = data->lst_imgs->next;
		}
		free(data->mlx);
		exit(0);
	}
	if (key == SWITCH && i > 0)
		cam_shift(data);
	return (0);
}
