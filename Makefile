NAME = ActivitiesDayFinder
GCCF = gcc -Wall -Werror -Wextra #-g3 -fsanitize=address
GREEN       = \033[32m
RED         = \033[31m
DEFAULT     = \033[37m
PATHOBJ = obj/
PATHSRC = src/
INCLUDE_PATH = include/
DEP = Makefile src/$(INCLUDE_PATH)/main.h
SRC =   main.c					\
		debug_ft.c				\
		pars_and_fill_data.c
HEAD = -I ./src/$(INCLUDE_PATH)/ -I
OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))
ECHO = echo

all: $(NAME)

$(PATHOBJ):
	@mkdir -p $(PATHOBJ)

$(NAME): $(PATHOBJ) $(addprefix $(PATHSRC)/,$(SRC)) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.$(DEFAULT)"
	@$(GCCF) $(OBJ) $(LIBFT) -o $(NAME)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(PATHOBJ)/%.o: $(PATHSRC)/%.c $(DEP)
	@$(ECHO) "\r$(GREEN) Compiling $<                 \c\033[K"
	@$(GCCF) $(HEAD) -c $< -o $@

clean:
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@make clean -C ./libft/
	@rm -rf $(PATHOBJ)

fclean: clean
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft