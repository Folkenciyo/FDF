/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:57 by juguerre          #+#    #+#             */
/*   Updated: 2024/02/05 23:25:24 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;
	char	*tmp;

	tmp = ft_strtrim(line, "\n");
	free(line);
	dots = ft_split(tmp, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(tmp);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

static int	ft_count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static t_dot	**mem_allocate(char *file)
{
	t_dot		**new_matrix;
	int			x;
	int			y;
	int			fd;
	char		*line;

	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		error_one("file does not exist", 1);
	line = get_next_line(fd);
	x = ft_count_words(line, ' ');
	free(line);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	new_matrix = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new_matrix[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new_matrix);
}

t_dot	**read_map(char *file)
{
	t_dot		**matrix;
	int			y;
	int			fd;
	char		*line;

	matrix = mem_allocate(file);
	fd = open(file, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_dots_from_line(line, matrix, y++);
		line = get_next_line(fd);
	}
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
