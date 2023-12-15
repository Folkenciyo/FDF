/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:07:57 by juguerre          #+#    #+#             */
/*   Updated: 2023/12/15 20:46:49 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_matrix	**allocate_memory_matrix(char *file)
{
	t_matrix	**matrix;
	int			fd;
	int			map_width;
	int			map_height;
	char		*line;

	fd = open(file, O_RDONLY);
	if (fd  == -1)
		error_two("Error: File ", file, 1);
	matrix = (t_matrix **)malloc(sizeof(t_matrix));
	if (!matrix)
	{
		free(matrix);
		matrix = NULL;
		error_one("Error: Memory allocation failed\n", 1);
	}
	printf("matrix = %p\n", matrix);
	printf("fd = %d\n", fd);
	line = get_next_line(fd);
	map_width = ft_count_words(line, ' ');
	free(line);
	map_height = 1;
	line = get_next_line(fd);
	while (line != 0)
	{
		free(line);
		line = get_next_line(fd);
		map_height++;
	}
	free(line);
	close(fd);
	return (matrix);
}

t_matrix	**read_map(char *file)
{
	t_matrix	**matrix;
	//int			fd;
	//int			y;
	//char		*line;

	matrix = allocate_memory_matrix(file);
	return (matrix);
}
