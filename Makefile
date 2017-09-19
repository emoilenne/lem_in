# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/23 09:55:14 by ofedorov          #+#    #+#              #
#    Updated: 2017/09/19 13:09:19 by sasha            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem_in

CC			=	gcc
CFLAGS		+=	-Wall -Werror -Wextra
RM			=	/bin/rm
RMFLAGS		+=	-rf

SRCS		=	main.c \
				parse_file.c \
				print_result.c \
				solve.c \
				get_index.c \
				free_and_exit.c \


LIBFT		=	ft_atoi.c \
				ft_error_exit.c \
				ft_lstaddend.c \
				ft_lstdel.c \
				ft_lstdelcontent.c \
				ft_lstnew.c \
				ft_memalloc.c \
				ft_memcpy.c \
				ft_putchar.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_strlen.c \
				ft_strlst_toarr.c \
				ft_strsplit.c \
				ft_strsplit_free.c \
				get_next_line.c \

OBJS		=	$(addprefix objs/,$(SRCS:.c=.o))
OBJS		+=	$(addprefix objs/,$(LIBFT:.c=.o))


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Objects created."
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJS) -o $@
	@echo "Program created."

objs:
	@mkdir $@

objs/%.o: libft/%.c | objs
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

objs/%.o: srcs/%.c | objs
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	@$(RM) $(RMFLAGS) $(OBJS)
	@echo "Objects deleted"
	@$(RM) $(RMFLAGS) objs

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "Program deleted."

re: fclean all
