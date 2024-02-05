/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 23:24:10 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "colours.h"
# include "error_msg.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include "../minilibx_macos/mlx.h"

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
	void		*mlx_ptr;
}				t_window;

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	*window;
}				t_dot;

t_dot			**read_map(char *file_name);
void			draw(t_dot **matrix, t_window *window);
int				deal_key(int key, t_dot **matrix);
void			set_window(t_dot *a, t_dot *b, t_window *window);
void			print_menu(t_window *window);
void			new_window(int key, t_dot **matrix, t_window *window);
int				ft_color(t_dot a, t_dot b);
float			ft_max(float a, float b);
float			ft_min(float a, float b);
void			error_one(char *str_perror, int exit_);
void			error_two(char *str_perror, char *file, int exit_);

#endif