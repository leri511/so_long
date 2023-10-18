/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:35:53 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/16 12:19:22 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(t_vars *vars, char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	j = 1;
	i = 1;
	height = vars->win_h;
	width = vars->win_w;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == 'P')
			{
				vars->x_p = j;
				vars->y_p = i;
			}
			j++;
		}
		i++;
	}
}

void	free_map_to_check(t_point *point)
{
	int	i;
	int	win_h;

	win_h = point->map_h;
	i = 0;
	while (i < win_h)
	{
		free(point->map_to_check[i]);
		i++;
	}
	free(point->map_to_check);
	free(point);
}

char	**cpy_map(t_vars *vars, t_point *point)
{
	int	i;
	int	j;

	point->map_h = vars->win_h;
	point->map_w = vars->win_w;
	point->map_to_check = (char **)malloc(point->map_h * sizeof(char *));
	if (point->map_to_check == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < point->map_h)
	{
		j = 0;
		point->map_to_check[i] = 
			(char *)malloc((point->map_w + 1) * sizeof(char));
		if (point->map_to_check[i] == NULL)
			exit(EXIT_FAILURE);
		while (j < point->map_w)
		{
			point->map_to_check[i][j] = vars->map[i][j];
			j++;
		}
		point->map_to_check[i][point->map_w] = '\0';
		i++;
	}
	return (point->map_to_check);
}

int	flood_fill_exit(t_point *point, int p_y, int p_x)
{
	int		c_x;
	int		c_y;
	int		win_h;
	int		win_w;
	char	**map;

	map = point->map_to_check;
	c_x = p_x;
	c_y = p_y;
	win_w = point->map_w;
	win_h = point->map_h;
	if (c_y < 1 || c_x < 1 || c_y >= win_h || c_x >= win_w)
		return (0);
	if (map[c_y][c_x] == '1' || map[c_y][c_x] == 'F')
		return (0);
	if (map[c_y][c_x] == 'E')
		return (1);
	map[c_y][c_x] = 'F';
	if (flood_fill_exit(point, c_y + 1, c_x)
		|| flood_fill_exit(point, c_y - 1, c_x)
		|| flood_fill_exit(point, c_y, c_x + 1)
		|| flood_fill_exit(point, c_y, c_x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_vars *vars, t_point *point)
{
	int	p_x;
	int	p_y;
	int	canreachexit;

	point = ft_calloc(sizeof(t_point), 1);
	cpy_map(vars, point);
	find_player_pos(vars, vars->map);
	p_x = vars->x_p;
	p_y = vars->y_p;
	canreachexit = flood_fill_exit(point, p_y, p_x);
	if (!canreachexit)
	{
		printf("can not reach the exit");
		exit(1);
	}
	free_map_to_check(point);
}
