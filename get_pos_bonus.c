/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:09:04 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:22 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pos(t_data *gm, int y, int x, int a)
{
	int static	o;

	if (a == 1337)
	{
		if (gm->map[y][x] == 'P')
		{
			gm->p_x = x;
			gm->p_y = y;
		}
		else if (gm->map[y][x] == 'X')
		{
			gm->e1_x[o] = x;
			gm->e1_y[o] = y;
			o++;
		}
	}
}
