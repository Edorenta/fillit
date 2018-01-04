/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:39:25 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/04 14:46:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		grid_insert(unsigned __int128 *tab, unsigned __int128 *grid,
		int grid_size, int len)
{
	int		i;
	int		nb_shift;

	i = 0;
	nb_shift = 0;
	while (i < len)
	{
		if (tab[i] & *grid)
			while (!(ft_rshift(&tab[i], grid_size, &nb_shift)))
			{
				nb_shift = 0;
				tab[i] = block_init(tab[i], grid_size);
				i--;
				if (i < 0)
					return (0);
				*grid ^= tab[i];
			}
		else
		{
			*grid |= tab[i];
			i++;
			nb_shift = 0;
		}
	}
	return (1);
}
