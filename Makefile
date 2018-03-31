# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knikanor <knikanor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 18:35:46 by knikanor          #+#    #+#              #
#    Updated: 2018/03/30 23:13:21 by knikanor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= fdf

LIBFT_DIR:= ./libft/
LIBFT:= $(LIBFT_DIR)libft.a
LIBFT_INC:= $(LIBFT_DIR)includes/
LIBFT_FLAGS:= -lft -L $(LIBFT_DIR)


CC:= gcc
CFLAGS:= -Wall -Wextra -Werror
SRC_DIR:= ./srcs/
OBJ_DIR:= ./obj/
INC_DIR:= ./includes/
COD:= .cache_exists
HEADER_FLAGS:= -I $(INC_DIR) -I $(LIBFT_INC)

END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
YELLOW:="\033[1;33m"

SRC:= 	\
		main.c \
		get_info.c \
		rendering.c \
		projection.c \
		keys.c \
		init.c \
		legend.c \

OBJ:= $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -o3 $(OBJ) $(LIBFT_FLAGS) -o $(NAME) -framework AppKit -framework OpenGL -lmlx
	@echo $(RED) "\n--- $@ is ready to be executed ---" $(YELLOW) "(^.^) \n" $(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER_FLAGS)
	@echo $(CYAN)".......\c" $(END)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
