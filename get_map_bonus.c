/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:01:39 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set(t_data *gm)
{
	gm->tm = NULL;
	gm->n_door = 0;
	gm->n_empty = 0;
	gm->n_bool = 0;
	gm->n_hero = 0;
	gm->n_wall = 0;
	gm->n_enemy1 = 0;
	gm->count = 0;
	gm->e1_x = NULL;
	gm->e1_y = NULL;
	gm->speed = FRAM_MOV;
	gm->hay_ola_miyit = 1;
	gm->diraction = 1;
}

static void	check_char(t_data *gm, char c)
{
	if (c == '1')
		gm->n_wall++;
	else if (c == '0')
		gm->n_empty++;
	else if (c == 'P')
		gm->n_hero++;
	else if (c == 'C')
		gm->n_bool++;
	else if (c == 'X')
		gm->n_enemy1++;
	else if (c == 'E')
		gm->n_door++;
	else
		free_and_err(gm, "you entered undefined semble !", 0, 42);
}

static void	check_map_name(char *map_name)
{
	char	*tmp;

	tmp = ft_strrchr(map_name, '.');
	if (!tmp)
		print_error("please enter a \".ber\" type map");
	if (ft_strcmp(tmp, ".ber"))
		print_error("please enter a \".ber\" type map");
}

static void	check_the_map(t_data *gm)
{
	int	i;
	int	j;

	i = 0;
	gm->map_width = ft_strlen(gm->map[i]);
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			check_char(gm, gm->map[i][j]);
			j++;
		}
		if (gm->map_width != j)
			free_and_err(gm, "The map must be rectangular !", 0, 42);
		i++;
	}
	gm->map_height = i;
	more_of_check(gm);
}

void	get_map(t_data *gm, char *map_name)
{
	char	*tmp;
	int		fd;

	set(gm);
	check_map_name(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		print_error("open map failed !");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (*tmp == '\n')
			more_free(tmp, gm->tm);
		gm->tm = ft_strjoin(gm->tm, tmp);
		free(tmp);
	}
	if (!gm->tm)
		print_error("your map looks like empty !");
	gm->map = ft_split(gm->tm, '\n');
	free(gm->tm);
	if (!gm->map)
		free_and_err(gm, "bad thing happened !!!", 0, 42);
	check_the_map(gm);
}
