/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitshift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 22:57:58 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/11 21:03:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		rshift_col(t_uint128 *mask, size_t grid_size)
{
	t_uint128	tmp;
	size_t		i;

	i = grid_size;
	tmp = 0;
	while (i <= (grid_size * grid_size))
	{
		tmp |= ((t_uint128)1 << (128 - i));
		i += grid_size;
	}
	return ((*mask & tmp) ? 0 : 1);
}

static	int		rshift_row(t_uint128 *mask, size_t grid_size)
{
	t_uint128	tmp;
	size_t		i;

	i = 1;
	tmp = 0;
	while (i <= grid_size)
	{
		tmp |= ((t_uint128)1 << (127 - (grid_size * grid_size - i)));
		i++;
	}
	return ((*mask & tmp) ? 0 : 1);
}

int				ft_rshift(t_uint128 *mask, size_t grid_size, int *nb_shift)
{
	if (rshift_col(mask, grid_size))
	{
		*mask >>= 1;
		*nb_shift += 1;
		return (1);
	}
	if (*nb_shift)
	{
		*mask <<= *nb_shift;
		*nb_shift = 0;
	}
	if (rshift_row(mask, grid_size))
	{
		*mask >>= grid_size;
		return (1);
	}
	return (0);
}
