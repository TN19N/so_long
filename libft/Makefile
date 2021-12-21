# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 16:32:30 by mannouao          #+#    #+#              #
#    Updated: 2021/12/15 17:14:32 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_split.c\
		ft_strcmp.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strrchr.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<
	@ar rcs $(NAME) $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
