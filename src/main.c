/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:12:11 by juguerre          #+#    #+#             */
/*   Updated: 2023/12/07 21:28:19 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init(1000, 1000, "Hello world!", 0);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}