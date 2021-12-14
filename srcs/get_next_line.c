/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanykim <chanykim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:34:27 by chanykim          #+#    #+#             */
/*   Updated: 2021/03/09 15:15:06 by chanykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		find_newline(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return (i);
		}
		i++;
	}
	return (-1);
}

int		line_store(char **backup, char **line, int size)
{
	char	*tmp;
	int		len;

	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + size + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	tmp = ft_strdup(*backup + size + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		check_backup(char **backup, char **line, int rd_size)
{
	int		size;

	if (rd_size < 0)
		return (-1);
	size = 0;
	if (*backup && (size = find_newline(*backup)) >= 0)
		return (line_store(backup, line, size));
	if (*backup)
	{
		*line = *backup;
		*backup = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			rd_size;
	int			size;
	char		*tmp;
	static char *backup[20];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	size = 0;
	while ((rd_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd_size] = '\0';
		tmp = (backup[fd] == NULL) ?
			ft_strdup(buff) : ft_strjoin(backup[fd], buff);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if ((size = find_newline(backup[fd])) >= 0)
			return (line_store(&backup[fd], line, size));
	}
	return (check_backup(&backup[fd], line, rd_size));
}
