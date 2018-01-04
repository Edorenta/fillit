/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_print_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:17:54 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/04 14:49:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	outp(char *str, size_t grid_size)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((i % grid_size) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void			print_grid(unsigned __int128 *blocks, size_t grid_size,
				size_t nb_blocks)
{
	int			i;
	int			j;
	unsigned __int128	x;
	char		*str;

	i = -1;
	str = (char *)malloc(sizeof(char) * (grid_size * grid_size + 1));
	str = ft_memset(str, '.', grid_size * grid_size);
	while (++i < (int)nb_blocks)
	{
		x = 0;
		j = -1;
		x |= (unsigned __int128)1 << 127;
		while (++j < ((int)grid_size * (int)grid_size))
		{
			if (blocks[i] & x)
				str[j] = 'A' + i;
			if (str[j] == '.')
				str[j] = '.';
			x >>= 1;
		}
	}
	outp(str, grid_size);
}
