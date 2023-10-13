# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:39:26 by ffons-ti          #+#    #+#              #
#    Updated: 2023/10/13 16:03:03 by ffons-ti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRC_FILES		= main parse utils commands exit

SRC_DIR			= srcs/
OBJ_DIR			= objs/
LIBFT_DIR		= libft/
LIBFT			= $(LIBFT_DIR)libft.a
INCLUDE			= include/

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)
OFLAGS			= -lreadline

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

$(NAME)			:	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OFLAGS) $^ -o $@
					@echo "Program Created"

all:				$(NAME)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

$(LIBFT):			$(LIBFT_DIR)
					@make -C $(LIBFT_DIR)

clean:
	@echo "Clean Boys!"
	@$(RM) ${OBJ} 
	@${RM} -r ${OBJ_DIR}
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@echo "Super Clean Boys!"
	@${RM} ${OBJS} ${NAME} ${LIBFT}

re: fclean all

norm:          
		@norminette $(INCLUDE) $(LIBFT_DIR) $(SRC_DIR) $(B_DIR)| grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus re-all re-bonus