/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:16:41 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/17 13:27:20 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_moves(t_data *gm)
{	
	gm->tm = ft_itoa(gm->count);
	mlx_string_put(gm->ml, gm->wi, 0, 0, 0x00FFFFFF, gm->tm);
	free(gm->tm);
}

static void	alloc(t_data *gm)
{
	gm->e1_x = (int *)malloc(sizeof(int) * gm->n_enemy1);
	if (!gm->e1_x)
		free_and_err(gm, "allocation faild :( !", 0, 8);
	gm->e1_y = (int *)malloc(sizeof(int) * gm->n_enemy1);
	if (!gm->e1_y)
		free_and_err(gm, "allocation faild :( !", 0, 8);
}

static void	put_imgs(t_data *gm, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_wl, x * PP, y * PP + 20);
	else if (c == '0')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_et, x * PP, y * PP + 20);
	else if (c == 'P')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_h, x * PP, y * PP + 20);
	else if (c == 'C')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_bl, x * PP, y * PP + 20);
	else if (c == 'X')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_e1, x * PP, y * PP + 20);
	else if (c == 'E')
		mlx_put_image_to_window(gm->ml, gm->wi, gm->im_d, x * PP, y * PP + 20);
}

static void	creat_imags(t_data *gm)
{
	int	t;

	gm->im_d = mlx_xpm_file_to_image(gm->ml, "m/door_c.xpm", &t, &t);
	gm->im_h = mlx_xpm_file_to_image(gm->ml, "m/pac_wright.xpm", &t, &t);
	gm->im_wl = mlx_xpm_file_to_image(gm->ml, "m/1.xpm", &t, &t);
	gm->im_bl = mlx_xpm_file_to_image(gm->ml, "m/food.xpm", &t, &t);
	gm->im_et = mlx_xpm_file_to_image(gm->ml, "m/empty.xpm", &t, &t);
	gm->im_e1 = mlx_xpm_file_to_image(gm->ml, "m/enemy.xpm", &t, &t);
}

void	update(t_data *gm, int a)
{
	int		i;
	int		j;

	if (a == 1337)
	{
		alloc(gm);
		creat_imags(gm);
	}
	i = 0;
	mlx_clear_window(gm->ml, gm->wi);
	while (gm->map[i])
	{
		j = 0;
		while (gm->map[i][j])
		{
			if (gm->map[i][j] == 'P' || gm->map[i][j] == 'X')
				get_pos(gm, i, j, a);
			put_imgs(gm, gm->map[i][j], j, i);
			j++;
		}
		i++;
	}
	print_moves(gm);
}
