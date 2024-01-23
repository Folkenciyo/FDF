/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:58 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/23 20:27:44 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_window *window)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_put_string(window->mlx_ptr, window->win_ptr, 10, 5);
	menu = "5, spase: 3d/2d mode; +, -: zoom";
	mlx_put_string(window->mlx_ptr, window->win_ptr, 10, 20);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_put_string(window->mlx_ptr, window->win_ptr, 10, 35);
	menu = "f: full screen mode";
	mlx_put_string(window->mlx_ptr, window->win_ptr, 10, 50);
}
