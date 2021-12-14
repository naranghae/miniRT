/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:15:50 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		co_free(t_list *lst_co)
{
	t_cone *co;

	while (lst_co->next)
	{
		co = (t_cone *)(lst_co->content);
		free(co);
		lst_co = lst_co->next;
	}
	lst_free(&lst_co);
	return (0);
}
