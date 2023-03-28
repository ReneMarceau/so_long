/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:14:13 by rmarceau          #+#    #+#             */
/*   Updated: 2022/11/28 13:06:14 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

// ------------------------------ Struct ------------------------------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ------------------------------ Verifs ------------------------------------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// ------------------------------ Length ------------------------------------
size_t	ft_strlen(const char *s);

// ------------------------------ Memory ------------------------------------
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

// ------------------------------ Strl ------------------------------------
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// ------------------------------ Ft_to* ----------------------------------
int		ft_toupper(int c);
int		ft_tolower(int c);

// ------------------------------ Ft_str ------------------------------------
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);

// ------------------------------ Ft_*to* -----------------------------------
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// ---------------------------- String manip ---------------------------------
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

// -------------------------- Func for each * --------------------------------
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// ----------------------------- Write func ----------------------------------
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_fd(int nb, char *base, int fd);

// ----------------------------- Linked list ----------------------------------
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ----------------------------- Ft_printf ----------------------------------
int		ft_printf(const char *format, ...);
int		ft_formats(va_list arg, const char format);
int		ft_print_char(int c);
int		ft_print_str(char *str);
void	ft_printnbr_base(long nb, char *base, int *length);

// --------------------------- get_next_line --------------------------------
char	*get_next_line(int fd);
char	*ft_get_line(char *stash);
char	*ft_clean_stash(char *stash);
char	*ft_get_strjoin(char *stash, char *buff);

#endif
