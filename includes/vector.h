/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 06:02:05 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/11 12:00:05 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

t_vec			ft_vec_create(double x, double y, double z);
t_vec			ft_vec_add(t_vec u, t_vec v);
t_vec			ft_vec_sub(t_vec u, t_vec v);
t_vec			ft_vec_multi_double(t_vec v, double t);
t_vec			ft_vec_div_double(t_vec v, double t);
double			ft_vec_dot(t_vec u, t_vec v);
t_vec			ft_vec_cross(t_vec u, t_vec v);
double			ft_vec_len(t_vec new_vec);
double			ft_vec_len_sqrt(t_vec new_vec);
t_vec			ft_vec_normalize(t_vec v);
t_vec			vec_reflect(t_vec v, t_vec n);
double			ft_dot_mine(t_vec vec);
void			ft_print_vec(t_vec vec);
t_vec			ft_vec_minus(t_vec u);
double			ft_vec_dist(t_vec u, t_vec v);
t_vec			select_normal(t_ray ray, t_vec nv);
double			cosval(t_vec a, t_vec b);
double			vec_size(t_vec v);
#endif
