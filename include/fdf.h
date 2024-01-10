/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/10 21:19:17 by juguerre         ###   ########.fr       */
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
# include "/Users/juguerre/Desktop/FDF/FDF/MLX42/include/MLX42/MLX42.h"

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
	int			color;
	int 		map_height;
	int 		map_width;
}				t_dot;

typedef struct s_window
{
	int			scale;
	int			z_scale;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	int			shift_x;
	int			shift_y;
	void		*win_ptr;
}				t_window;

typedef struct s_matrix
{
	t_dot	**map;
	int		map_h;
	int		map_w;
}				t_matrix;

/**** Read File Functions ****/

t_matrix	*read_map(char *file);

/**** Error Functions ****/
void		error_one(char *str_perror, int exit_);

void		error_two(char *str_perror, char *file, int exit_);

#endif