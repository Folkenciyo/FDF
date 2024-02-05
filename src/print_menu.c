/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:58 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 21:13:12 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	half_menu_print(t_window *window, char *menu)
{
	menu = "up";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 80, 4, 0xfff4b2, menu);
	menu = "^";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 83, 21, 0xfff4b2, menu);
	menu = "down";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 70, 55, 0xfff4b2, menu);
	menu = "V";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 83, 36, 0xfff4b2, menu);
	menu = "|";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 83, 26, 0xfff4b2, menu);
	menu = "left <-";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 25, 0xfff4b2, menu);
	menu = "-> right";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 96, 25, 0xfff4b2, menu);
	menu = "3D-2D: 5";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 82, 0xf6e57c, menu);
}

void	print_menu(t_window *window)
{
	char	*menu;

	menu = NULL;
	half_menu_print(window, menu);
	menu = "Zoom: -- ";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 124, 0xfbe042, menu);
	menu = "|+|";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 65, 110, 0xfbe042, menu);
	menu = "|-|";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 65, 135, 0xfbe042, menu);
	menu = "f: full screen mode";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 170, 0xfbd803, menu);
	menu = "Z-Scale: 2 & 8";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 195, 0xf0c43d, menu);
	menu = "Rotate: 4 & 6";
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 220, 0xF0B23D, menu);
}
