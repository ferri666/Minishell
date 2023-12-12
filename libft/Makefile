# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 19:24:41 by ffons-ti          #+#    #+#              #
#    Updated: 2023/12/09 11:31:58 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_calloc.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strdup.c \
					ft_tolower.c ft_bzero.c   ft_isascii.c ft_strnstr.c \
					ft_memmove.c ft_strlen.c  ft_strrchr.c ft_substr.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_strjoin.c ft_itoa.c    ft_strtrim.c ft_split.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_atoi2.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c ft_atoi2.c  ft_lstfirst.c \
					get_next_line.c ft_allupper.c ft_alllower.c ft_capword.c \
					ft_findchr.c ft_free_matrix.c ft_printf.c ft_printhex.c \
					ft_printnbr.c ft_printptr.c ft_format.c ft_countchr.c \
					ft_nlines.c ft_check_fd.c
					
OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= 

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "Libft.a created!"

%.o:			%.c
				@$(CC) $(CFLAGS) -o $@ -c $^

all:			$(NAME)


clean:
				@$(RM) $(OBJS)
				@echo "Clean library!"
				

fclean:			clean
				@$(RM) $(NAME)
				@echo "Super clean library!"

re:				fclean $(NAME)

norm:			
				@norminette | grep -v Norme -B1 || true

.PHONY:			all clean fclean re norm