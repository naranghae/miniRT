/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:35:26 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:15:38 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		get_next_line(int fd, char **line);
int		find_newline(char *s);
int		line_store(char **backup, char **line, int size);
int		check_backup(char **backup, char **line, int rd_size);
#endif
