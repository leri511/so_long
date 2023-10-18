/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:23:52 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/16 12:21:13 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "GNL/get_next_line.h"
# include <mlx.h>

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				map_w;
	int				map_h;
	int				map_x;
	int				map_y;
	int				movement;
	char			**map;
	int				collect;
}	t_vars;

typedef struct s_point {
	char	**map_to_check;
	int		map_h;
	int		map_w;
	int		p_x;
	int		p_y;
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
}	t_point;

//read fd
char	**get_map(char *fmap);
//
char	**ft_split(char const *s, char c);
//put img
void	put_image(t_vars ***v, int x, int y, char *img);
void	put_image_to_map(char p, int x1, int y1, t_vars **v);
//put img on screen
int		get_height(char **map);
void	render_map(t_vars *vars);
//checks
void	check_file_is_valid(char *file_line);
void	check_map(t_vars *vars);
void	check_elements(t_vars **vars);
//key
void	to_up(t_vars **v);
void	to_right(t_vars **v);
void	to_left(t_vars **v);
void	to_down(t_vars **v);
//exit
int		ft_exit(t_vars *v);
void	exit_door(t_vars ***v);
//error
void	ft_error(t_vars ***v, char *err);
//flood_fill
int		flood_fill_exit(t_point *point, int p_y, int p_x);
void	flood_fill(t_vars *vars, t_point *map);
void	find_player_pos(t_vars *vars, char **map);
char	**cpy_map(t_vars *vars, t_point *point);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	free_map_to_check(t_point *point);
//moves
void	put_text(t_vars ***v);
char	*ft_itoa(int n);
char	*ft_join_strings(char const *s1, char const *s2);
void	flood_fill_c(t_vars *vars, t_point *point);
int		flood_fill_coins(t_point *point, int p_y, int p_x, int *a);
int		find_coins_ff(char **map);

#endif