/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:23:42 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/16 12:39:50 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	render_map(t_vars *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 64;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 64;
		vars->win_h--;
	}
}

static void	init_vars(t_vars *vars, t_point *point)
{
	vars->movement = 0;
	vars->collect = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
	flood_fill(vars, point);
	flood_fill_c(vars, point);
}

static void	create(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			vars->win_w * 64, vars->win_h * 64, "So-Long");
	render_map(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_point	*point;

	point = ft_calloc(sizeof(t_point), 1);
	if (argc != 2)
	{
		printf("no map\n");
		exit(1);
	}
	(void)argv;
	check_file_is_valid(argv[1]);
	vars.map = get_map(argv[1]);
	if (vars.map != NULL)
	{
		check_map(&vars);
		init_vars(&vars, point);
		create(&vars);
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_loop(vars.mlx);
	}
	return (0);
}
