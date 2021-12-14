/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 16:55:57 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft/libft.h"

t_mw		*malloc_mlx(void)
{
	t_mw *mlx;

	if (!(mlx = (t_mw *)malloc(sizeof(*mlx))))
		ft_error(MALLOC_FAIL);
	if (!(mlx->mlx_p = mlx_init()))
		ft_error(MLX_ERROR);
	return (mlx);
}

void		make_img_ptr(t_imgs *lstimgs, t_data *data, t_area *resolution)
{
	int		w;
	int		h;

	mlx_get_screen_size(data->mlx->mlx_p, &w, &h);
	if (w < resolution->w)
		resolution->w = w;
	if (h < resolution->h)
		resolution->h = h;
	if (!(lstimgs->img = mlx_new_image(data->mlx->mlx_p, resolution->w,
		resolution->h)))
		ft_error(MLX_ERROR);
	if (!(lstimgs->addr = mlx_get_data_addr(lstimgs->img,
		&(lstimgs->bits_per_pixel), &(lstimgs->size_line),
		&(lstimgs->endian))))
		ft_error(MLX_ERROR);
}

int			*init_img(t_data *data, t_rt_info *info, t_area *resolution)
{
	t_imgs	*lstimgs;
	t_list	*cam;

	data->lst_imgs = NULL;
	data->i = info->cam_num;
	cam = info->camera;
	while (info->cam_num--)
	{
		printf("img: %d\n", info->cam_num);
		if (!(lstimgs = (t_imgs *)malloc(sizeof(*lstimgs))))
			ft_error(MALLOC_FAIL);
		make_img_ptr(lstimgs, data, resolution);
		make_img(lstimgs, info, cam->content);
		cam = cam->next;
		circle_lstadd(&(data->lst_imgs), ft_lstnew(lstimgs));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data		mlx_data;
	t_rt_info	*info;
	t_imgs		*imgs;
	char		*title;

	start_error_check(argc, argv);
	info = put_info(argv);
	printf("check R - w: %d   h: %d\n", info->resolution.w, info->resolution.h);
	mlx_data.mlx = malloc_mlx();
	init_img(&mlx_data, info, &info->resolution);
	imgs = mlx_data.lst_imgs->content;
	title = argv[1];
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		bmp_save(&mlx_data, info->resolution, ft_strjoin(argv[1], "_"));
	if (!(mlx_data.mlx->win_p = mlx_new_window(mlx_data.mlx->mlx_p,
		info->resolution.w, info->resolution.h, title)))
		ft_error(MLX_ERROR);
	printf("finished\n");
	rt_free(info);
	mlx_put_image_to_window(mlx_data.mlx->mlx_p, mlx_data.mlx->win_p,
		imgs->img, 0, 0);
	mlx_hook(mlx_data.mlx->win_p, KEYPRESS, 1L << 0, ft_key_press, &mlx_data);
	mlx_loop(mlx_data.mlx->mlx_p);
	return (0);
}
