/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:39 by juguerre          #+#    #+#             */
/*   Updated: 2023/12/15 19:46:26 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "/Users/juguerre/Desktop/FDF/fdf/MLX42/include/MLX42/MLX42.h"

typedef struct s_matrix
{
	int	**map;
	int	map_height;
	int	map_width;
}				t_matrix;

/**** Read File Functions ****/

t_matrix	**read_map(char *file);

/**** Error Functions ****/
void		error_one(char *str_perror, int exit_);

void		error_two(char *str_perror, char *file, int exit_);

#endif