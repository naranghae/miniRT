/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 16:56:05 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	add_header(char *file, unsigned int size, t_area win)
{
	int n;

	ft_memcpy(file, "BM", 2);
	n = size + HEADER_SIZE;
	ft_memcpy(file + 2, &n, 4);
	n = 0;
	ft_memcpy(file + 6, &n, 4);
	n = HEADER_SIZE;
	ft_memcpy(file + 10, &n, 4);
	n = INFO_HEADER_SIZE;
	ft_memcpy(file + 14, &n, 4);
	ft_memcpy(file + 18, &(win.w), 4);
	ft_memcpy(file + 22, &(win.h), 4);
	n = 1;
	ft_memcpy(file + 26, &n, 2);
	n = 24;
	ft_memcpy(file + 28, &n, 2);
	n = 0;
	ft_memcpy(file + 30, &n, 4);
	ft_memcpy(file + 34, &size, 4);
	ft_memcpy(file + 38, &n, 4);
	ft_memcpy(file + 42, &n, 4);
	ft_memcpy(file + 46, &n, 4);
	ft_memcpy(file + 50, &n, 4);
}

void	add_img(char *file, t_imgs *img, t_area win)
{
	int x;
	int y;
	int i;
	int j;

	i = HEADER_SIZE;
	y = win.h;
	while (y--)
	{
		x = 0;
		while (x < win.w)
		{
			j = y * img->size_line + x * (img->bits_per_pixel / 8);
			ft_memcpy(file + i, img->addr + j, 3);
			i += 3;
			++x;
		}
	}
}

void	export_bmp(t_imgs *imgs, t_area win, char *name)
{
	t_bmp			bmp;
	unsigned int	bmp_size;

	bmp.fd = 0;
	bmp.name = name;
	win.w = win.w - win.w % 4;
	bmp_size = win.w * win.h * 3;
	if ((bmp.file = (char *)malloc(bmp_size + HEADER_SIZE)) == NULL)
		ft_error(MALLOC_FAIL);
	add_header(bmp.file, bmp_size, win);
	add_img(bmp.file, imgs, win);
	if ((bmp.fd = open(bmp.name, (O_RDWR | O_CREAT | O_TRUNC), \
											FILE_PERMISSION)) < 0)
		ft_error(ERROR_CREATE_FILE);
	if (write(bmp.fd, bmp.file, bmp_size + HEADER_SIZE) < 0)
		ft_error(ERROR_WRITE_FILE);
	write(1, bmp.name, ft_strlen(bmp.name));
	write(1, "\n", 1);
	close(bmp.fd);
	free(bmp.name);
	free(bmp.file);
}

void	bmp_save(t_data *data, t_area win, char *filename)
{
	t_imgs	*lst_imgs;
	char	*name;
	int		i;

	i = data->i;
	while (data->lst_imgs->next && data->i--)
	{
		data->lst_imgs = data->lst_imgs->next;
		lst_imgs = data->lst_imgs->content;
		name = ft_strjoin(filename, ft_itoa(data->i));
		export_bmp(lst_imgs, win, ft_strjoin(name, ".bmp"));
		free(name);
	}
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
