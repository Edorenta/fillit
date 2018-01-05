/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_block_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:14:38 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/04 14:51:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					get_blocks(char *file)
{
	int		handle;
	int		j;
	int		i;
	char	*str;
	char	buf[1];

	i = 0;
	j = 1;
	if ((handle = open(file, O_RDONLY)) == -1)
		return (0);
	while ((read(handle, buf, 1)))
		i++;
	close(handle);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))) || !str)
		return (0);
	read((handle = open(file, O_RDONLY)), str, i);
	str[i++] = '\0';
	close(handle);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	return (j / 5);
}

static	int			is_free_col(__uint128 block, size_t grid_size)
{
	__uint128	mask;
	size_t		i;

	i = 1;
	mask = 0;
	while (i <= (grid_size * grid_size))
	{
		mask |= ((__uint128)1 << (128 - i));
		i += grid_size;
	}
	return ((block & mask) ? 0 : 1);
}

static	int			is_free_row(__uint128 block, size_t grid_size)
{
	__uint128	mask;
	size_t		i;

	i = 0;
	mask = 0;
	while (i < grid_size)
	{
		mask |= ((__uint128)1 << (127 - i));
		i++;
	}
	return ((block & mask) ? 0 : 1);
}

__uint128			block_init(__uint128 block, size_t grid_size)
{
	while (is_free_row(block, grid_size))
		block = block << grid_size;
	while (is_free_col(block, grid_size))
		block = block << 1;
	return (block);
}
