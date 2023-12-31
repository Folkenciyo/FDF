/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:12:11 by juguerre          #+#    #+#             */
/*   Updated: 2023/12/15 18:42:53 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_matrix **matrix;
	
	if (argc != 2)
		error_one("Error: Wrong number of arguments\n", 1);
	matrix = read_map(argv[1]);
	return (0);
}