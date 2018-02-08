/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:41:34 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/18 17:27:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		gridsize(int nb_blocks)
{
	int		grid_size;

	grid_size = 3;
	while ((grid_size * grid_size) < (nb_blocks * 4))
		grid_size++;
	return (grid_size);
}

static	int		grid_fix(int nb_blocks, t_uint128 *blocks)
{
	t_uint128	*nbr;
	t_uint128	one;
	int			ret;

	nbr = 0;
	one = 1;
	ret = 3;
	IS_INT((nbr = (t_uint128 *)malloc(sizeof(t_uint128) * 3)));
	nbr[0] |= (one << 127 | one << 123 | one << 119 | one << 115);
	nbr[1] |= (one << 127 | one << 126 | one << 125 | one << 124);
	nbr[2] |= (one << 127 | one << 126 | one << 123 | one << 122);
	if (nb_blocks == 1)
	{
		if (blocks[0] == nbr[0] || blocks[0] == nbr[1])
			ret = 4;
		else if (blocks[0] == nbr[2])
			ret = 2;
	}
	else if (blocks[0] == (one << 127 | one << 124 | one << 121 | one << 118)
		|| blocks[1] == (one << 127 | one << 124 | one << 121 | one << 118))
		ret = 4;
	free(nbr);
	return (ret);
}

int				main(int ac, char **av)
{
	t_uint128			*tab;
	t_uint128			bit_grid;
	int					nb_blocks[0];
	int					grid_size;

	if (check_init(ac, nb_blocks, av[1]))
		return (put_err(check_init(ac, nb_blocks, av[1])));
	grid_size = gridsize(nb_blocks[0]);
	bit_grid = 0;
	if (!(tab = (t_uint128 *)malloc(sizeof(t_uint128) * nb_blocks[0])))
		return (put_err(0));
	tab = txt_to_tab(av[1], tab, &grid_size, nb_blocks[0]);
	grid_size = (grid_size == 3) ? grid_fix(nb_blocks[0], tab) : grid_size;
	tab = txt_to_tab(av[1], tab, &grid_size, nb_blocks[0]);
	while (!(grid_insert(tab, &bit_grid, grid_size, nb_blocks[0])))
	{
		grid_size++;
		bit_grid = 0;
		tab = txt_to_tab(av[1], tab, &grid_size, nb_blocks[0]);
	}
	print_grid(tab, grid_size, nb_blocks[0]);
	free(tab);
	return (0);
}
