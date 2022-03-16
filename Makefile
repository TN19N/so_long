# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:45:07 by mannouao          #+#    #+#              #
#    Updated: 2022/03/16 10:33:37 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = mlx/libmlx.a
NAME = so_long
LIBFT = libft/libft.a
BONUS_SRCS = so_long_bonus.c\
		error_bonus.c\
		get_next_line_bonus.c\
		more_of_check_bonus.c\
		get_map_bonus.c\
		move_the_hero_bonus.c\
		update_bonus.c\
		move_the_enemy_bonus.c\
		get_pos_bonus.c

SRCS = so_long.c\
		error.c\
		get_next_line.c\
		more_of_check.c\
		get_map.c\
		move_the_hero.c\
		update.c\
		get_pos.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : bonus

bonus : $(BONUS_OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(XFLAGS) $(MLX) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C libft

$(MLX):
	@make -C mlx

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@make -C mlx clean
	@make -C libft -f Makefile clean
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@make -C mlx fclean
	@make -C libft -f Makefile fclean
	@rm -f $(NAME)

re : fclean all