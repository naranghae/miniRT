/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:14:49 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		sp_free(t_list *lst_sp)
{
	t_sphere *sp;

	while (lst_sp->next)
	{
		sp = (t_sphere *)(lst_sp->content);
		free(sp);
		lst_sp = lst_sp->next;
	}
	lst_free(&lst_sp);
	return (0);
}

int		pl_free(t_list *lst_pl)
{
	t_plane *pl;

	while (lst_pl->next)
	{
		pl = (t_plane *)(lst_pl->content);
		free(pl);
		lst_pl = lst_pl->next;
	}
	lst_free(&lst_pl);
	return (0);
}

int		sq_free(t_list *lst_sq)
{
	t_square *sq;

	while (lst_sq->next)
	{
		sq = (t_square *)(lst_sq->content);
		free(sq);
		lst_sq = lst_sq->next;
	}
	lst_free(&lst_sq);
	return (0);
}

int		tr_free(t_list *lst_tr)
{
	t_triangle *tr;

	while (lst_tr->next)
	{
		tr = (t_triangle *)(lst_tr->content);
		free(tr);
		lst_tr = lst_tr->next;
	}
	lst_free(&lst_tr);
	return (0);
}

int		cy_free(t_list *lst_cy)
{
	t_cylinder *cy;

	while (lst_cy->next)
	{
		cy = (t_cylinder *)(lst_cy->content);
		free(cy);
		lst_cy = lst_cy->next;
	}
	lst_free(&lst_cy);
	return (0);
}
