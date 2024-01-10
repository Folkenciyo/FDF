/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:12:11 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/10 21:00:59 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_window *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->win_ptr = mlx_init(param->win_x, param->win_y, "FDF", 0);
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
	mlx_loop(window->win_ptr);
	return (0);
}