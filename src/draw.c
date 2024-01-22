/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/22 21:04:46 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	zoom(t_dot *a, t_dot *b, t_window *window)
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

void	line(t_dot a, t_dot b, t_window *window)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_window(&a, &b, window);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_put_pixel(window->img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > window->win_x || a.y > window->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	ft_draw(t_dot **matrix, t_window *window)
{
	int		y;
	int		x;

	//print_menu(window);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], window);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
