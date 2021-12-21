/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:30:12 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:25 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	if_is_ther(char *saver)
{
	if (!saver)
		return (0);
	while (*saver)
	{
		if (*saver == '\n')
			return (1);
		saver++;
	}
	return (0);
}

static char	*get_next(char *saver)
{
	char	*new_saver;
	int		i;
	int		j;

	i = 0;
	while (saver[i] && saver[i] != '\n')
		i++;
	if (!saver[i])
	{
		free(saver);
		return (NULL);
	}
	new_saver = (char *)malloc(sizeof(char) * (ft_strlen(saver) - i));
	if (!new_saver)
		return (NULL);
	i++;
	j = 0;
	while (saver[i + j])
	{
		new_saver[j] = saver[i + j];
		j++;
	}
	new_saver[j] = '\0';
	free(saver);
	return (new_saver);
}

static char	*get_line(char *saver)
{
	char	*line;
	int		i;

	i = 0;
	while (saver[i] && saver[i] != '\n')
		i++;
	if (saver[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (saver[i] && saver[i] != '\n')
	{
		line[i] = saver[i];
		i++;
	}
	if (saver[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_fill(int fd, char *saver)
{
	char		*buff;
	int			i;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!if_is_ther(saver) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		saver = ft_strjoin(saver, buff);
	}
	free(buff);
	return (saver);
}

char	*get_next_line(int fd)
{
	static char	*saver;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saver = get_fill(fd, saver);
	if (!saver)
		return (NULL);
	if (!saver[0])
	{
		free(saver);
		saver = NULL;
		return (NULL);
	}
	line = get_line(saver);
	saver = get_next(saver);
	return (line);
}
