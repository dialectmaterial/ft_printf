# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dcrooijm <dcrooijm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/13 12:23:19 by dcrooijm      #+#    #+#                  #
#    Updated: 2021/12/13 13:32:35 by dcrooijm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printfutils/ft_printstr.c ft_printfutils/ft_printnbr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar rs $@ $^

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re:	fclean all
