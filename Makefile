# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:39:26 by ffons-ti          #+#    #+#              #
#    Updated: 2023/12/12 19:21:23 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRC_FILES		= main parse utils commands exit errors_parse parse_utils redirections split_args cmd \
					expand expand_utils env signals
EXEC_FILES		= main_exec utils_exec
BUILT_FILES		= ft_cd ft_echo ft_exit ft_pwd
SRC_DIR			= srcs/
EXEC_DIR		= $(SRC_DIR)exec/
BUILT_DIR		= $(SRC_DIR)builtins/
OBJ_DIR			= objs/
LIBFT_DIR		= libft/
LIBFT			= $(LIBFT_DIR)libft.a
INCLUDE			= include/

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE) -g3 -fsanitize=address -I /Users/$(USER)/.brew/opt/readline/include/ 
OFLAGS			=  -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include/ -lreadline

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
EXEC_SRC 		= 	$(addprefix $(EXEC_DIR), $(addsuffix .c, $(EXEC_FILES)))
EXEC_OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(EXEC_FILES)))
BUILT_SRC 		= 	$(addprefix $(BUILT_DIR), $(addsuffix .c, $(BUILT_FILES)))
BUILT_OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BUILT_FILES)))

$(NAME)			:	$(OBJ) $(EXEC_OBJ) $(BUILT_OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OFLAGS) $^ -o $@
					@echo "Program Created"

all:				$(NAME)

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

$(OBJ_DIR)%.o	: 	$(EXEC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

$(OBJ_DIR)%.o	: 	$(BUILT_DIR)%.c
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
		@norminette | grep -v "OK" || echo "\033[0;34m\n==> \033[0;36mNo norm errors!!\033[0m 🆗🆗🆗\n"

.PHONY: all clean fclean re norm bonus re-all re-bonus