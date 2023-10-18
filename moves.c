/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:04:01 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/16 12:18:49 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collected(t_vars ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collect--;
	(**v)->map[((**v)->y_p / 64)][((**v)->x_p / 64)] = '0';
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, (**v)->x_p, (**v)->y_p);
}

void	to_up(t_vars **v)
{
	int	img_h;
	int	img_w;

	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx, (*v)->win,
		(*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_right(t_vars **v)
{
	int	img_h;
	int	img_w;

	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] != '1')
	{
		(*v)->x_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_left(t_vars **v)
{
	int	img_h;
	int	img_w;

	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] != '1')
	{
		(*v)->x_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_down(t_vars **v)
{
	int	img_h;
	int	img_w;

	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image((*v)->mlx,
			"./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx,
		(*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}
