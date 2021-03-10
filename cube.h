/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:36:04 by adidion           #+#    #+#             */
/*   Updated: 2021/03/08 12:02:14 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# define BUFFER_SIZE 32
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
# define INT_MAX 2147483647
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_map
{
	int			**tab;
	int			x;
	int			y;
	int			start;
	int			l;
	int			ll;
}				t_map;

int				ft_parse_count(char *str);
t_map			ft_parse_init(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_return(int i, char *s);
int				ft_newline(char *s);
char			*ft_static(char *s);
char			*ft_line(char *s);
int				ft_protect(char *s, char *buff);
int				get_next_line(int fd, char **line);
char			*get_next_line_2(int fd, char **line);
int				ft_check_line(char *line);
t_list			*ft_lst_fill(int fd);
char			*ft_protect_2(char *s, char *buff);
t_list			*ft_lstadd_back(t_list *alst, t_list *new);
t_list			*ft_lstnew(char *content);
t_list			*ft_lst_fill_2(t_list *lst, char *str);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, int (*f)(const char*, ...));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
int				ft_lstsize(t_list *lst);
int				**ft_int_tab_fill(t_list *lst, int i);
int				*ft_fill_one_entry(char *str, int **a);
int				ft_value_int(char c);
int				*ft_free_tab(int **a);
t_map			ft_fill_start_struct(int **tab, int a);
void			ft_print_tab(int **tab);
int				ft_test_map(int **tab);
int				ft_test_ext(char *str);
int         	ft_mlx(t_map start);
t_map       	ft_window_size(t_map start, int fd);
int				ft_atoi(const char *str);

#endif
