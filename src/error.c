/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:58:26 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/31 13:49:24 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_one(char *str_perror, int exit_)
{
	perror(str_perror);
	exit(exit_);
}

void	error_two(char *str_perror, char *file, int exit_)
{
	ft_printf("%s: %s\nNo such file or directory: %s\n",
		str_perror, strerror(errno), file);
	exit(exit_);
}
