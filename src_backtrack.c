/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:39:25 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/13 14:36:51 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		*init_mem(int *array, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
		array[i] = 0;
	return (array);
}

static	int		freeturn(int *array, int ret)
{
	free(array);
	return (ret);
}

int				grid_insert(t_uint128 *tab, t_uint128 *grid,
		int grid_size, int len)
{
	int		i;
	int		*nb_shift;

	IS_INT((init_mem((nb_shift = (int *)malloc(sizeof(int) * 500)), 500)));
	i = 0;
	while (i < len)
	{
		if (tab[i] & *grid)
			while (!(ft_rshift(&tab[i], grid_size, &nb_shift[i])))
			{
				nb_shift[i] = 0;
				tab[i] = block_init(tab[i], grid_size);
				if (--i < 0)
					return (freeturn(nb_shift, 0));
				*grid ^= tab[i];
			}
		else
		{
			*grid |= tab[i];
			i++;
			nb_shift[i] = 0;
		}
	}
	return (freeturn(nb_shift, 1));
}
