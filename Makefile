
NAME		=	lem_in

CC			=	gcc
CFLAGS		+=	-Wall -Werror -Wextra
RM			=	/bin/rm
RMFLAGS		+=	-rf

SRCSFL		=

SRCSFD		=	srcs
OBJSFD		=	objs
INCLFD		=	includes

SRCS		=	$(addprefix $(SRCSFD)/, $(SRCSFL))
OBJS		=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Objects created."
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJS) -o $@
	@echo "Program created."

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) -c $< -o $@

clean:
	@$(RM) $(RMFLAGS) $(OBJS)
	@echo "Objects deleted"
	@$(RM) $(RMFLAGS) $(OBJSFD)
	

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "Program deleted."
	

re: fclean all

