/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:29:04 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 23:24:31 by juguerre         ###   ########.fr       */
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

int	ft_color(t_dot a, t_dot b)
{
	int	color;

	if (a.z || b.z)
		color = 0xfc0345;
	else
		color = 0xBBFAFF;
	if (a.z != b.z)
		color = 0xfc031c;
	return (color);
}
