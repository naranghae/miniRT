/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/18 21:25:54 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		start_error_check(int ac, char **av)
{
	char	*file;

	file = av[1];
	while (file)
	{
		if (*file == '.')
			break ;
		file++;
	}
	if (ac < 2 || ac > 3)
		ft_error(WRONG_ARGUMENT);
	if (ac == 2 && ft_strncmp(file, ".rt", 3))
		ft_error(WRONG_RT_FILE);
	if (ac == 3 && ft_strncmp(av[2], "--save", 6))
		ft_error(WRONG_SAVE);
}

void		ft_error2(int i)
{
	if (i == 7)
		printf("Malloc error\n");
	else if (i == 8)
		printf("Init .rt info error\n");
	else if (i == 9)
		printf("Mlx init error\n");
	else if (i == 10)
		printf("Basic error check\n");
	else if (i == 11)
		printf("Bmp_error_create_file\n");
	else if (i == 12)
		printf("Bmp_error_write_file\n");
}

void		ft_error(int i)
{
	if (i == 0)
		printf("Wrong argument\n");
	else if (i == 1)
		printf("First argument must be a .rt\n");
	else if (i == 2)
		printf("Second argument must be --save\n");
	else if (i == 3)
		printf("Open function error\n");
	else if (i == 4)
		printf("Parsing error\n");
	else if (i == 5)
		printf("Close function error\n");
	else if (i == 6)
		printf("Mismatch type\n");
	ft_error2(i);
	exit(0);
}
