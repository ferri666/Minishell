# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:39:26 by ffons-ti          #+#    #+#              #
#    Updated: 2023/12/19 11:09:30 by ffons-ti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRC_FILES		= main exit env utils heredoc signals
EXEC_FILES		= main_exec utils_exec
BUILT_FILES		= ft_cd ft_echo ft_exit ft_pwd ft_export ft_env ft_unset
PARSE_FILES		= parse parse_utils errors_parse expand expand_utils split_args commands redirections
SRC_DIR			= srcs/
EXEC_DIR		= $(SRC_DIR)exec/
BUILT_DIR		= $(SRC_DIR)builtins/
PARSE_DIR		= $(SRC_DIR)parse/
OBJ_DIR			= objs/
LIBFT_DIR		= libft/
LIBFT			= $(LIBFT_DIR)libft.a
INCLUDE			= include/

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE) -I /Users/$(USER)/.brew/opt/readline/include/ -g3 -fsanitize=address 
OFLAGS			= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
EXEC_SRC 		= 	$(addprefix $(EXEC_DIR), $(addsuffix .c, $(EXEC_FILES)))
EXEC_OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(EXEC_FILES)))
BUILT_SRC 		= 	$(addprefix $(BUILT_DIR), $(addsuffix .c, $(BUILT_FILES)))
BUILT_OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BUILT_FILES)))
PARSE_SRC 		= 	$(addprefix $(PARSE_DIR), $(addsuffix .c, $(PARSE_FILES)))
PARSE_OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(PARSE_FILES)))

$(NAME)			:	$(LIBFT) $(OBJ) $(EXEC_OBJ) $(BUILT_OBJ) $(PARSE_OBJ)
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
					
$(OBJ_DIR)%.o	: 	$(PARSE_DIR)%.c
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
