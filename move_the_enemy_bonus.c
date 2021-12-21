/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:07:32 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/17 16:19:57 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mv(t_data *gm, int y, int x, int i)
{
	if (gm->map[gm->e1_y[i] + y][gm->e1_x[i] + x] == '0')
	{
		gm->map[gm->e1_y[i] + y][gm->e1_x[i] + x] = 'X';
		gm->map[gm->e1_y[i]][gm->e1_x[i]] = '0';
		gm->e1_y[i] += y;
		gm->e1_x[i] += x;
	}
	else if (gm->map[gm->e1_y[i] + y][gm->e1_x[i] + x] == 'P')
	{
		gm->map[gm->e1_y[i] + y][gm->e1_x[i] + x] = 'X';
		gm->map[gm->e1_y[i]][gm->e1_x[i]] = '0';
		gm->e1_y[i] += y;
		gm->e1_x[i] += x;
		gm->hay_ola_miyit = 0;
		printf("Game Over !!!\n");
	}
}

static void	move_e(t_data *gm, int i)
{
	int	tmp1;
	int	tmp2;

	tmp1 = gm->p_x - gm->e1_x[i];
	tmp2 = gm->p_y - gm->e1_y[i];
	if (tmp1 < 0)
		tmp1 *= -1;
	if (tmp2 < 0)
		tmp2 *= -1;
	if ((tmp1 <= tmp2 && tmp1 != 0) || tmp2 == 0)
	{
		if (gm->p_x > gm->e1_x[i])
			mv(gm, 0, 1, i);
		else
			mv(gm, 0, -1, i);
	}
	else
	{
		if (gm->p_y > gm->e1_y[i])
			mv(gm, 1, 0, i);
		else
			mv(gm, -1, 0, i);
	}
}

void	move_the_enemy(t_data *gm, int *ptr)
{
	int	i;

	i = gm->n_enemy1 - 1;
	while (i >= 0)
	{
		if (!gm->hay_ola_miyit)
			break ;
		move_e(gm, i);
		i--;
	}
	*ptr = 0;
	update(gm, 42);
}
