/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:44:59 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/15 16:54:08 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H
# define BUFFER_SIZE 1337
# define PP 64
# define FRAM 3500
# define FRAM_MOV 5000
# define MAX_HEIGHT 21
# define MAX_WIDTH 40
# define TIME_HELL 50000

# include "libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct v_data
{
	void	*ml;
	void	*wi;
	char	*tm;
	char	**map;
	int		n_hero;
	int		n_bool;
	int		n_door;
	int		n_empty;
	int		n_enemy1;
	int		n_wall;
	int		map_height;
	int		map_width;
	void	*im_h;
	void	*im_d;
	void	*im_et;
	void	*im_e1;
	void	*im_wl;
	void	*im_bl;
	int		t;
	int		p_x;
	int		p_y;
	int		count;
	int		*e1_x;
	int		*e1_y;
	int		diraction;
	int		speed;
	int		hay_ola_miyit;
}				t_data;

void	print_error(char *str);
void	get_map(t_data *gm, char *map_name);
char	*get_next_line(int fd);
void	free_and_err(t_data *gm, char *str, int i, int x);
void	more_of_check(t_data *gm);
void	update(t_data *gm, int a);
int		move_the_hero(int key, t_data *gm);
void	move_the_enemy(t_data *gm, int *ptr);
void	get_pos(t_data *gm, int x, int y, int a);
int		leav(t_data *gm);
void	more_free(char *ptr1, char *ptr2);

#endif