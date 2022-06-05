SRC		=	so_long.c src/get_map.c src/print_map.c src/mov_player.c 		   \
			src/collect_exit.c src/checker.c src/utils.c src/menu.c			   \
			src/before_mov.c src/tab_copy.c

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

GCC		=	gcc

RM		=	rm -rf

NAME	=	so_long

all:		$(NAME)

%.o: %.c
			@$(GCC) $(FLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C ./lib42
			@$(GCC) $(FLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./lib42/libft.a
			@echo "\033[1;32mCompilation complete ✅"

clean:
			@$(RM) $(OBJS)
			@$(MAKE) clean -C ./lib42
			@echo "\033[1;32mCleaning complete 🧽"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C ./lib42
			@echo "\033[1;32mFull cleaning complete 🧹"

re:			fclean all
			@echo "\033[1;32mRebuild complete 🔨"

.PHONY:		all fclean clean re
