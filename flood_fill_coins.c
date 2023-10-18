/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_coins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:29:54 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/15 15:23:20 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_coins_ff(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	flood_fill_coins(t_point *point, int p_y, int p_x, int *a)
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
	if (c_y < 1 || c_x < 1 || map[c_y][c_x] == '1' || map[c_y][c_x] == 'F')
		return (0);
	if (c_y >= win_h || c_x >= win_w)
		return (0);
	if (map[c_y][c_x] == 'C')
		*a += 1;
	map[c_y][c_x] = 'F';
	if (flood_fill_coins(point, c_y + 1, c_x, a)
		|| flood_fill_coins(point, c_y - 1, c_x, a)
		|| flood_fill_coins(point, c_y, c_x + 1, a)
		|| flood_fill_coins(point, c_y, c_x - 1, a))
		return (1);
	return (0);
}

void	flood_fill_c(t_vars *vars, t_point *point)
{
	int	p_x;
	int	p_y;
	int	a;
	int	coins_needed;

	a = 0;
	point = ft_calloc(sizeof(t_point), 1);
	cpy_map(vars, point);
	find_player_pos(vars, vars->map);
	p_x = vars->x_p;
	p_y = vars->y_p;
	coins_needed = find_coins_ff(vars->map);
	flood_fill_coins(point, p_y, p_x, &a);
	if (a != coins_needed)
	{
		printf("can not reach all coins");
		exit(1);
	}
	free_map_to_check(point);
}
