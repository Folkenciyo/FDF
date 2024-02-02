/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/31 17:10:23 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	line(t_dot a, t_dot b, t_window *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_window(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix, t_window *window)
{
	int		y;
	int		x;

	print_menu(window);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], window);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], window);
			if (matrix[y][x].is_last != 0)
				break ;
			x++;
		}
		y++;
	}
}
