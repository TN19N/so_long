/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_of_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:43:19 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/15 15:06:45 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	last_check(t_data *gm)
{
	if (gm->n_door == 0 || gm->n_hero == 0 || gm->n_bool == 0)
		free_and_err(gm, "please enter at least 1 sart 1 exit 1 food !", 0, 42);
	if (gm->n_hero > 1)
		free_and_err(gm, "please enter just one start !", 0, 42);
	if (gm->map_height > MAX_HEIGHT || gm->map_width > MAX_WIDTH)
		free_and_err(gm, "the map is so big !", 0, 42);
}

void	more_of_check(t_data *gm)
{
	int	i;

	i = 0;
	while (gm->map[0][i])
	{
		if (gm->map[0][i] != '1')
			free_and_err(gm, "the map must be surrounded by walls !", 0, 42);
		i++;
	}
	i = 0;
	while (gm->map[i])
	{
		if (gm->map[i][gm->map_width - 1] != '1')
			free_and_err(gm, "the map must be surrounded by walls !", 0, 42);
		if (gm->map[i][0] != '1')
			free_and_err(gm, "the map must be surrounded by walls !", 0, 42);
		i++;
	}
	i = -1;
	while (gm->map[gm->map_height - 1][++i])
		if (gm->map[gm->map_height - 1][i] != '1')
			free_and_err(gm, "the map must be surrounded by walls !", 0, 42);
	last_check(gm);
}
