
NAME		=	lem_in

CC			=	gcc
CFLAGS		+=	-Wall -Werror -Wextra
RM			=	/bin/rm
RMFLAGS		+=	-rf

SRCSFL		=	main.c \
			parse_file.c \
			print_result.c \
			solve.c \
			get_index.c \

SRCSFD		=	srcs
OBJSFD		=	objs
INCLFD		=	includes libft/includes

LIBFT		=	libft/libft.a
LIBFTLIB	=	-Llibft -lft

SRCS		=	$(addprefix $(SRCSFD)/, $(SRCSFL))
OBJS		=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Objects created."
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJS) $(LIBFTLIB) -o $@
	@echo "Program created."

$(OBJSFD):
	@mkdir $@

$(LIBFT): $(LIBFTFD)
	@make -C libft re

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) -c $< -o $@

clean:
	@$(RM) $(RMFLAGS) $(OBJS)
	@echo "Objects deleted"
	@$(RM) $(RMFLAGS) $(OBJSFD)
	@make -C libft clean

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "Program deleted."
	@make -C libft fclean

re: fclean all
