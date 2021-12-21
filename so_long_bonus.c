/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:44:51 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/17 16:21:50 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	time_hell(t_data *gm, int *j)
{
	int			t;
	static int	x;

	if (x == TIME_HELL)
	{
		mlx_destroy_image(gm->ml, gm->im_e1);
		gm->im_e1 = mlx_xpm_file_to_image(gm->ml, "m/enemy2.xpm", &t, &t);
		if (*j >= FRAM_MOV / 2)
			*j = FRAM_MOV / 2;
		gm->speed = FRAM_MOV / 2;
	}
	if (x == TIME_HELL * 2)
	{
		mlx_destroy_image(gm->ml, gm->im_e1);
		gm->im_e1 = mlx_xpm_file_to_image(gm->ml, "m/enemy.xpm", &t, &t);
		gm->speed = FRAM_MOV;
		x = 0;
	}
	x++;
}

static void	chose_wich_diraction(t_data *gm)
{
	int	t;

	mlx_destroy_image(gm->ml, gm->im_h);
	if (gm->diraction == 1)
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_wright.xpm", &t, &t);
	else if (gm->diraction == 2)
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_down.xpm", &t, &t);
	else if (gm->diraction == 3)
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_left.xpm", &t, &t);
	else if (gm->diraction == 4)
		gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_up.xpm", &t, &t);
}

static void	open_door(t_data *gm)
{
	int static	i;
	int			t;

	if (i == 0)
	{
		mlx_destroy_image(gm->ml, gm->im_d);
		gm->im_d = mlx_xpm_file_to_image(gm->ml, "m/door_o.xpm", &t, &t);
		update(gm, 42);
		i++;
	}
}

static int	inimatins(t_data *g)
{
	static int	j;
	static int	i;

	if (g->hay_ola_miyit)
	{
		if (i++ == FRAM)
		{	
			mlx_destroy_image(g->ml, g->im_h);
			g->im_h = mlx_xpm_file_to_image(g->ml, "m/pc_f.xpm", &g->t, &g->t);
			update(g, 42);
		}
		else if (i++ >= FRAM * 2)
		{
			chose_wich_diraction(g);
			update(g, 42);
			i = 0;
		}
		time_hell(g, &j);
		if (g->n_bool == 0)
			open_door(g);
		if (j++ == g->speed)
			move_the_enemy(g, &j);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	gm;
	int		tmp1;
	int		tmp2;

	if (ac != 2)
		print_error("please enter one map !");
	get_map(&gm, av[1]);
	gm.ml = mlx_init();
	printf("moves -> %d\n", gm.count);
	tmp1 = gm.map_width * PP;
	tmp2 = gm.map_height * PP;
	gm.wi = mlx_new_window(gm.ml, tmp1, tmp2 + 20, "so_long");
	update(&gm, 1337);
	mlx_key_hook(gm.wi, &move_the_hero, &gm);
	mlx_loop_hook(gm.ml, &inimatins, &gm);
	mlx_hook(gm.wi, 17, 0L, &leav, &gm);
	mlx_loop(gm.ml);
}
