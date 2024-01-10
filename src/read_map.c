/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:57 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/10 22:00:25 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dots_from_line(char *line, t_dot **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
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
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

int	ft_count_words(char *str, char c)
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

static t_matrix	*mem_allocate(char *file)
{
	t_matrix	*matrix;
	int			fd;
	int			y;
	char		*line;

	matrix = (t_matrix *)malloc(sizeof(t_matrix *));
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	matrix->map_h = 1;
	matrix->map_w = ft_count_words(line, ' ');
	while (get_next_line(fd))
	{
		matrix->map_h++;
	}
	close(fd);
	matrix->map = (t_dot **)malloc(sizeof(t_dot *) * (matrix->map_h + 1));
	matrix->map[matrix->map_h + 1] = NULL;
	y = 0;
	while (y < matrix->map_h)
	{
		matrix->map[y] = (t_dot *)malloc(sizeof(t_dot) * (matrix->map_w + 1));
		matrix->map[y][matrix->map_w].is_last = 1;
		y++;
	}
	matrix->map[y] = NULL;
	return (matrix);
}

void print_matrix(t_dot **matrix)
{
    int y = 0;
    int x;

	printf("PLAES\n");
    while (matrix[y])
    {
        x = 0;
        while (!matrix[y][x].is_last)
        {
            printf("Point at matrix[%d][%d]: x = %f, y = %f, z = %f\n", y, x, matrix[y][x].x, matrix[y][x].y, matrix[y][x].z);
            x++;
        }
        y++;
    }
}

t_matrix	*read_map(char *file)
{
	t_matrix	*matrix;
	int			y;
	int			fd;
	char		*line;

	matrix = mem_allocate(file);
	fd = open(file, O_RDONLY, 0);
	y = 0;
	while (y > matrix->map_h)
	{
		line = get_next_line(fd);
		get_dots_from_line(line, matrix->map, y);
		y++;
	}
	print_matrix(matrix->map);
	matrix->map[y] = NULL;
	close(fd);
	return (matrix);
}
