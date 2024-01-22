/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:12:11 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/22 21:08:10 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_window *window)
{
	window->scale = 15;
	window->z_scale = 1;
	window->is_isometric = 1;
	window->angle = 0.523599;
	window->win_x = 2000;
	window->win_y = 1000;
	window->shift_x = window->win_x / 3;
	window->shift_y = window->win_y / 3;
	window->win_ptr = mlx_init(window->win_x, window->win_y, "FDF", 0);
	window->img = mlx_new_image(window->win_ptr, SIZE, SIZE);
}

int	main(int argc, char **argv)
{
	t_window	*window;
	t_matrix	*matrix;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		error_one("Error: Malloc failed\n", 1);
	if (argc != 2)
		error_one("Error: Wrong number of arguments\n", 1);
	matrix = read_map(*++argv);
	set_default(window);
	ft_draw(matrix->map, window);
	mlx_image_to_window(window->win_ptr, window->img, 350, 0);
	mlx_loop(window->win_ptr);
	return (0);
}