CFLAGS	= gcc -Wall -Wextra -Werror -o
NAME	= push_swap
MAKE	= make
SRC = src/push_swap.c \
	sort_a_lot/sort_3.c sort_a_lot/general_sort.c sort_a_lot/general_sort_utilities.c sort_a_lot/find_mouvement.c sort_a_lot/instructions_do.c \
	rules/stack_utilities_1.c rules/stack_utilities_2.c rules/reverse_rotate.c rules/rotate.c rules/swap_push.c \
	tree/avl_tree_utilities.c tree/insert.c tree/median_search.c\
	control/primary.c \

all: credit $(NAME)
	@echo "██████████████████ Compiled ██████████████████"
	@echo "\033[1;33mMartini\033[m"
$(NAME):
	@$(MAKE) -C inc/libft/ re
	$(CFLAGS) $(NAME) $(SRC) -L inc/libft/ -lft -I inc

clean:
	@$(MAKE) -C inc/libft/ clean

fclean:
	rm -f $(NAME)
	@$(MAKE) -C inc/libft/ fclean

re: fclean all

credit:
	@echo " __ __   __   ___  _____  _  __  _  _ "
	@echo "|  V  | /  \ | _ \|_   _|| ||  \| || |"
	@echo "| \_/ || /\ || v /  | |  | || | ' || |"
	@echo "|_| |_||_||_||_|_\  |_|  |_||_|\__||_|"
	@echo "                         \033[0;95mAlp A. Yalman\033[m"

