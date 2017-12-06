/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:13:43 by ckrommen          #+#    #+#             */
/*   Updated: 2017/12/06 14:13:07 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remalloc(char *line)
{
	char	*new;

	new = ft_strnew(ft_strlen(line) + 1);
	if (new)
	{
		ft_strncpy(new, (char *)line, (ft_strlen(line)));
		free(line);
		return (new);
	}
	return (NULL);
}

int		ft_get_line(char **temp, int fd, char **line)
{
	char	buf;
	int		i;

	i = 0;
	if (!temp[fd])
		temp[fd] = ft_strnew(BUFF_SIZE);
	while (read(fd, &buf, BUFF_SIZE))
	{
		if (temp[fd])
		{
			if (buf == '\n')
			{
				temp[fd][i] = '\0';
				*line = ft_strdup(temp[fd]);
				return (1);
			}
		}
		else
			temp[fd] = ft_remalloc(temp[fd]);
		temp[fd][i] = buf;
		i++;
	}
	return (0);
}

int		ft_get_next_line(const int fd, char **line)
{
	static char *temp[4894];

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (ft_get_line(&temp[fd], fd, line))
		return (1);
	return (0);
}
