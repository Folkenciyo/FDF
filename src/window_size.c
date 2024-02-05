/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:35:33 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 21:27:55 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_win_size(int key, t_window *window)
{
	if ((key == 0 && window->win_y <= 500)
		|| (key == 6 && window->win_x <= 500))
		return (1);
	if ((key == 1 && window->win_y > 1000)
		|| (key == 7 && window->win_x > 2000))
		return (1);
	return (0);
}

static void	window_change(t_window *window, int old_x, int old_y)
{
	if (window->win_x == 2560)
		window->win_x = old_x;
	else
		window->win_x = 2560;
	if (window->win_y == 1400)
		window->win_y = old_y;
	else
		window->win_y = 1400;
}

static void	full_screen(t_window *window)
{
	static int	old_x;
	static int	old_y;

	if (window->win_x != 2560)
	{
		old_x = window->win_x;
		old_y = window->win_y;
	}
	window_change(window, old_x, old_y);
}

static void	change_window_size(int key, t_window *window)
{
	if (check_win_size(key, window))
		return ;
	if (key == 6)
		window->win_x -= 100;
	if (key == 7)
		window->win_x += 100;
	if (key == 0)
		window->win_y -= 100;
	if (key == 1)
		window->win_y += 100;
	if (key == 3)
		full_screen(window);
}

void	new_window(int key, t_dot **matrix, t_window *window)
{
	change_window_size(key, window);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	window->mlx_ptr = mlx_init();
	window->win_ptr = \
	mlx_new_window(window->mlx_ptr, window->win_x, window->win_y, "FDF");
	window->shift_x = window->win_x / 3;
	window->shift_y = window->win_y / 3;
	draw(matrix, window);
	mlx_key_hook(window->win_ptr, deal_key, matrix);
	mlx_loop(window->mlx_ptr);
}
