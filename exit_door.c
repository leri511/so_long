/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:45:57 by hsievier          #+#    #+#             */
/*   Updated: 2023/08/16 12:27:52 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_door(t_vars ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	mlx_destroy_window((**v)->mlx, (**v)->win);
	exit(0);
}

int	ft_exit(t_vars *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(0);
	return (0);
}
