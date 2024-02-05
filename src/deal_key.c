/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:23:57 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 21:24:02 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_isometric(int iso)
{
	if (iso == 0)
	{
		return (1);
	}
	return (0);
}

static int	is_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22);
}

static void	do_key(int key, t_window *window)
{
	if (key == 24 || key == 69)
		window->scale += 3;
	if (key == 27 || key == 78)
		window->scale -= 3;
	if (key == 91 || key == 28)
		window->z_scale += 1;
	if (key == 84 || key == 19)
		window->z_scale -= 1;
	if (key == '~')
		window->shift_y -= 10;
	if (key == '}')
		window->shift_y += 10;
	if (key == '{')
		window->shift_x -= 10;
	if (key == '|')
		window->shift_x += 10;
	if (key == 49 || key == 87 || key == 23)
		window->is_isometric = is_isometric(window->is_isometric);
	if (key == 86 || key == 21)
		window->angle += 0.05;
	if (key == 88 || key == 22)
		window->angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix)
{
	if (is_key(key))
	{
		mlx_clear_window(matrix[1]->window->mlx_ptr,
			matrix[1]->window->win_ptr);
		do_key(key, matrix[1]->window);
		print_menu(matrix[1]->window);
		draw(matrix, matrix[1]->window);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix, matrix[1]->window);
	if (key == '5')
	{
		mlx_destroy_window(matrix[1]->window->mlx_ptr,
			matrix[1]->window->win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
