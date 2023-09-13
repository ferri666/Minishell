/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:54 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/09/13 16:43:48 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdarg.h>
# define BUFFER_SIZE 1
# ifndef
#  define OPEN_MAX 10240
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*before;
}	t_dlist;

//// BASIC LIBFT /////

void		*ft_bzero(void *s, size_t len);

int			ft_isalpha(int c);

int			ft_isascii(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isprint(int c);

size_t		ft_strlen(const char *str);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		*ft_memset(void *b, int c, size_t len);

size_t		ft_strlcpy(char *dest, const char *src, size_t size);

size_t		ft_strlcat(char *dest, const char *src, size_t size);

int			ft_strncmp(char *s1, char *s2, size_t n);

int			ft_tolower(int c);

int			ft_toupper(int c);

char		*ft_strchr(char *str, char to_find);

char		*ft_strrchr(char *str, char to_find);

void		*ft_memchr(void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(const char *str);

char		*ft_strnstr(const char *str, const char *to_find, size_t len);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_itoa(int n);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

///////////////LIST////////////////////

t_dlist		*ft_lstnew(int content);

void		ft_lstadd_front(t_dlist **lst, t_dlist *new);

int			ft_lstsize(t_dlist *lst);

t_dlist		*ft_lstlast(t_dlist *lst);

void		ft_lstadd_back(t_dlist **lst, t_dlist *new);

void		ft_lstdelone(t_dlist *lst, void (*del)(void *));

void		ft_lstclear(t_dlist **lst, void (*del)(void *));

void		ft_lstiter(t_dlist *lst, void (*f)(void *));

t_dlist		*ft_lstmap(t_dlist *lst, int (*f)(void *), void (*del)(void *));

t_dlist		*ft_lstfirst(t_dlist *lst);

////// GNL //////////

char		*get_next_line(int fd);

char		*ft_free(char *buffer, char *buf);

///////  PRINTF //////////

int			ft_printchar(int c);

int			ft_printf(const char *format, ...);

int			ft_format(va_list arg, int i);

int			ft_printpercent(void);

int			ft_printstr(char *str);

int			ft_printnbr(int nbr);

int			ft_printhex(unsigned int nbr, const char f);

int			ft_printptr(unsigned long long ptr);

int			ft_printunsign(unsigned int nbr);

/// NEW  ///
char		*ft_alllower(char *s);

char		*ft_allupper(char *s);

char		*ft_capword(char *s);

int			find_chr(char *str, char c);

void		ft_free_matrix(void **matrix);

int			ft_countchr(char *str, char c);

long int	ft_atoi2(const char *str);

int			ft_nlines(char *file);

int			ft_check_fd(char *str);

#endif