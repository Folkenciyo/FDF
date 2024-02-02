/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:12:11 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/02 18:03:03 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*set_default(t_window *window)
{
	window->scale = 20;
	window->z_scale = 1;
	window->is_isometric = 1;
	window->angle = 0.523599;
	window->win_x = 2000;
	window->win_y = 1000;
	window->shift_x = window->win_x / 3;
	window->shift_y = window->win_y / 3;
	window->mlx_ptr = mlx_init();
	window->win_ptr = \
	mlx_new_window(window->mlx_ptr, window->win_x, window->win_y, "FDF");
	return (window);
}

int		main(int argc, char **argv)
{
	t_dot		**matrix;

	if (argc != 2)
		error_one("usage: ./fdf map.fdf", 1);
	matrix = read_map(*++argv);
	matrix[1]->window = malloc(sizeof(t_window));
	if (!matrix[1]->window)
		error_one("Error: Malloc failed\n", 1);
	matrix[1]->window = set_default(matrix[1]->window);
	draw(matrix, matrix[1]->window);
	mlx_key_hook(matrix[1]->window->win_ptr, deal_key, matrix);
	mlx_loop(matrix[1]->window->mlx_ptr);
	return (0);
}