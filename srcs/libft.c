/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/17 19:56:14 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include <limits.h>

void		circle_lstadd(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
	}
	else
	{
		new->next = (*lst)->next;
		(*lst)->next = new;
		*lst = new;
	}
}

double		ft_atod(char *str)
{
	int		num;
	int		neg;
	double	sol;

	num = 0;
	neg = 1;
	sol = 0.0;
	if (*str == '-' && *(str++))
		neg = -1;
	while (ft_isdigit(*str))
		num = num * 10 + (*(str++) - '0');
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
		sol = sol * 10 + (*(str++) - '0');
	while (sol >= 1)
		sol /= 10;
	sol += num;
	return (sol * neg);
}

int			ft_rt_atoi(char **str)
{
	int						sign;
	unsigned long long		sol;

	sign = 1;
	sol = 0;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	sign = (**str == '-') ? -1 : 1;
	if (**str == '-')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		sol = sol * 10 + **str - '0';
		if (sign == 1 && sol > LLONG_MAX)
			return (-1);
		else if (sign == -1 && sol > LLONG_MAX - 1)
			return (0);
		(*str)++;
	}
	return (sign * sol);
}

double		ft_rt_atod(char **str)
{
	int		num;
	int		neg;
	double	sol;

	num = 0;
	neg = 1;
	sol = 0.0;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
		num = num * 10 + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	while (ft_isdigit(**str))
		sol = sol * 10 + (*((*str)++) - '0');
	while (sol >= 1)
		sol /= 10;
	sol += num;
	return (sol * neg);
}
