/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:52:30 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/14 22:25:48 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_msg(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int	leav(t_data *gm)
{
	free_and_err(gm, "you leaved the game !", 1, 8);
	return (0);
}

void	print_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	free_and_err(t_data *gm, char *str, int k, int x)
{
	int	i;

	i = -1;
	if (gm->map)
	{
		while (gm->map[++i])
			free(gm->map[i]);
		free(gm->map);
	}
	if (gm->e1_x)
		free(gm->e1_x);
	if (gm->e1_y)
		free(gm->e1_y);
	if (x != 42)
		mlx_destroy_window(gm->ml, gm->wi);
	if (k == 0)
		print_error(str);
	else if (k == 1)
		print_msg(str);
}

void	more_free(char *ptr1, char *ptr2)
{
	if (ptr2)
		free(ptr2);
	free(ptr1);
	print_error("invalid map !!!!!!");
}
