/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:29:04 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/23 19:38:53 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_color(t_dot a, t_dot b)
{
	if (a.z || b.z)
		return (RED);
	if (a.z != b.z)
		return (MAGENTA);
	return (CYAN);
}
