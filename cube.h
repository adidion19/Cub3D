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
# define BUFFER_SIZE 246
# ifndef OPEN_MAX
#  define OPEN_MAX 32
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

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_map
{
	int			**tab;
	int			x;
	int			y;
	int			start;
	int			l;
	int			ll;
	char		*n_texture;
	char		*s_texture;
	char		*e_texture;
	char		*w_texture;
	char		*sprite_texture;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			cell_r;
	int			cell_g;
	int			cell_b;
	int			ext;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_rcst
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	double		old_time;
	double		cam_time;
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dest_x;
	double		side_dest_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_hight;
	int			draw_start;
	int			draw_end;
	t_mlx		window;
	t_map		start;
	t_data		data;
	t_data		xpm_n;
	t_data		xpm_e;
	t_data		xpm_s;
	t_data		xpm_w;
	int			color;
	int			**buffer;
	void		*txt;
	int			xor_color;
	int			y_color;
	int			xy_color;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	double		fov;
}				t_rcst;

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
int				ft_mlx(t_map start);
t_map			ft_window_size(char *file, t_map start, int fd);
int				ft_atoi(const char *str);
char			*ft_n_texture(t_list *lst);
char			*ft_s_texture(t_list *lst);
char			*ft_e_texture(t_list *lst);
char			*ft_w_texture(t_list *lst);
char			*ft_sprite_texture(t_list *lst);
t_map			ft_colours_floor(t_map start, t_list *lst);
t_map			ft_triple_atoi_floor(t_map start, char *str);
t_map			ft_colours_cell(t_map start, t_list *lst);
t_map			ft_triple_atoi_cell(t_map start, char *str);
int				ft_error(t_map start);
t_rcst			ft_rcst_fill(t_mlx window, t_map start, t_rcst ray_info);
t_rcst			ft_hook(t_rcst ray_info, t_mlx window);
t_rcst			ft_rcst_loop(t_mlx window, t_map start, t_rcst ray_info);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data			ft_data_fill(t_data img);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
char			*ft_protect_2(char *s, char *buff);
t_rcst			*ft_go_right(t_rcst *ray_info);
t_rcst			*ft_go_left(t_rcst *ray_info);
t_rcst			*ft_turn_left(t_rcst *ray_info);
t_list			*ft_lst_fill_2(t_list *lst, char *str);
t_data			ft_xpm_to_image_n(t_rcst ray_info);
t_data			ft_xpm_to_image_s(t_rcst ray_info);
t_data			ft_xpm_to_image_e(t_rcst ray_info);
t_data			ft_xpm_to_image_w(t_rcst ray_info);
t_rcst			ft_rcst_fill_3(t_rcst ray_info);
t_rcst			ft_rcst_fill_4(t_rcst ray_info);
t_rcst			ft_rcst_calculate_2(t_map start, t_rcst ray_info);
void			ft_draw_floor_and_cell(t_rcst ray_info, int x);
t_data			ft_data_fill(t_data img);
t_rcst			ft_rcst_calculate_3(t_map start, t_rcst ray_info);
t_rcst			ft_rcst_calculate_4(t_rcst ray_info, int x, int y);

#endif
