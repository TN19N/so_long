/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_the_hero_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:15:41 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:15 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_pac(t_data *gm, int x, int y)
{
	mlx_destroy_image(gm->ml, gm->im_h);
	if (x == 0 && y == -1)
	{
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_up.xpm", &x, &y);
		gm->diraction = 4;
	}
	else if (x == -1 && y == 0)
	{
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_left.xpm", &x, &y);
		gm->diraction = 3;
	}
	else if (x == 0 && y == 1)
	{
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_down.xpm", &x, &y);
		gm->diraction = 2;
	}
	else if (x == 1 && y == 0)
	{
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_wright.xpm", &x, &y);
		gm->diraction = 1;
	}
	update(gm, 42);
}

static void	move_to_empty_n_bool(t_data *gm, int x, int y, int a)
{
	gm->map[gm->p_y + y][gm->p_x + x] = 'P';
	gm->map[gm->p_y][gm->p_x] = '0';
	gm->p_y += y;
	gm->p_x += x;
	gm->count++;
	printf("moves -> %d\n", gm->count);
	if (a == 1)
	{
		gm->n_bool--;
		printf("you collected one ball you still need : %d\n", gm->n_bool);
	}
	update(gm, 42);
}

static void	move(t_data *gm, int x, int y)
{
	change_pac(gm, x, y);
	if (gm->map[gm->p_y + y][gm->p_x + x] == '1')
		return ;
	else if (gm->map[gm->p_y + y][gm->p_x + x] == 'X')
	{
		gm->map[gm->p_y][gm->p_x] = '0';
		gm->hay_ola_miyit = 0;
		printf("Game Over !!!\n");
		update(gm, 42);
	}
	else if (gm->map[gm->p_y + y][gm->p_x + x] == '0')
		move_to_empty_n_bool(gm, x, y, 0);
	else if (gm->map[gm->p_y + y][gm->p_x + x] == 'C')
		move_to_empty_n_bool(gm, x, y, 1);
	else if (gm->map[gm->p_y + y][gm->p_x + x] == 'E')
	{
		if (gm->n_bool == 0)
			free_and_err(gm, "you finished the game, great :)", 1, 8);
	}
}

int	move_the_hero(int key, t_data *gm)
{
	if (key == 53)
		free_and_err(gm, "thanks for playing my game :)", 1, 8);
	if (gm->hay_ola_miyit)
	{
		if (key == 13)
			move(gm, 0, -1);
		else if (key == 0)
			move(gm, -1, 0);
		else if (key == 1)
			move(gm, 0, 1);
		else if (key == 2)
			move(gm, 1, 0);
	}
	return (0);
}
