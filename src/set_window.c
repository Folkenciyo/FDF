/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:42:44 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 21:12:04 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

static void	zoom(t_dot *a, t_dot *b, t_window *window)
{
	a->x *= window->scale;
	a->y *= window->scale;
	b->x *= window->scale;
	b->y *= window->scale;
	a->z *= window->z_scale;
	b->z *= window->z_scale;
}

void	set_window(t_dot *a, t_dot *b, t_window *window)
{
	zoom(a, b, window);
	if (window->is_isometric)
	{
		isometric(a, window->angle);
		isometric(b, window->angle);
	}
	a->x += window->shift_x;
	a->y += window->shift_y;
	b->x += window->shift_x;
	b->y += window->shift_y;
}
