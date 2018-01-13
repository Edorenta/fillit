/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:41:34 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/13 14:03:14 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		gridsize(int nb_blocks)
{
	int		grid_size;

	grid_size = 4;
	while ((grid_size * grid_size) < (nb_blocks * 4))
		grid_size++;
	return (grid_size);
}

static	int		hard_grid_fix(t_uint128 *b, t_uint128 *nbr, t_uint128 one)
{
	nbr[3] |= (one << 127 | one << 126 | one << 125 | one << 123);
	nbr[4] |= (one << 125 | one << 123 | one << 122 | one << 121);
	nbr[5] |= (one << 127 | one << 126 | one << 121 | one << 118);
	nbr[6] |= (one << 126 | one << 122 | one << 119 | one << 118);
	nbr[7] |= (one << 127 | one << 126 | one << 125 | one << 121);
	nbr[8] |= (one << 127 | one << 123 | one << 122 | one << 121);
	nbr[9] |= (one << 127 | one << 123 | one << 119 | one << 118);
	nbr[10] |= (one << 127 | one << 126 | one << 122 | one << 118);
	if (((b[0] == nbr[3] || b[1] == nbr[3])
	&& (b[0] == nbr[4] || b[1] == nbr[4]))
	|| ((b[0] == nbr[5] || b[1] == nbr[5])
	&& (b[0] == nbr[6] || b[1] == nbr[6]))
	|| ((b[0] == nbr[7] || b[1] == nbr[7])
	&& (b[0] == nbr[8] || b[1] == nbr[8]))
	|| ((b[0] == nbr[9] || b[1] == nbr[9])
	&& (b[0] == nbr[10] || b[1] == nbr[10]))
	|| ((b[0] == nbr[2] || b[1] == nbr[2])
	&& ((b[0] == nbr[7] || b[1] == nbr[7])
	|| (b[0] == nbr[8] || b[1] == nbr[8])
	|| (b[0] == nbr[3] || b[1] == nbr[3])
	|| (b[0] == nbr[9] || b[1] == nbr[9])
	|| (b[0] == nbr[10] || b[1] == nbr[10]))))
		return (3);
	return (4);
}

static	int		grid_fix(int nb_blocks, t_uint128 *blocks)
{
	int			grid_size;
	t_uint128	*nbr;
	t_uint128	one;

	grid_size = 4;
	nbr = 0;
	one = 1;
	nbr = malloc(100 * 4);
	nbr[0] |= (one << 127 | one << 123 | one << 119 | one << 115);
	nbr[1] |= (one << 127 | one << 126 | one << 125 | one << 124);
	nbr[2] |= (one << 127 | one << 126 | one << 123 | one << 122);
	if (nb_blocks == 1)
	{
		if (blocks[0] == nbr[0] || blocks[0] == nbr[1])
			grid_size = 4;
		else if (blocks[0] == nbr[2])
			grid_size = 2;
		else
			grid_size = 3;
	}
	else if (nb_blocks == 2)
		grid_size = hard_grid_fix(blocks, nbr, one);
	free(nbr);
	return (grid_size);
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
	if (!(tab = (t_uint128 *)malloc(sizeof(tab[0]) * nb_blocks[0])))
		return (put_err(0));
	tab = txt_to_tab(av[1], tab, grid_size, nb_blocks[0]);
	grid_size = (grid_size == 4) ? grid_fix(nb_blocks[0], tab) : grid_size;
	tab = txt_to_tab(av[1], tab, grid_size, nb_blocks[0]);
	while (!(grid_insert(tab, &bit_grid, grid_size, nb_blocks[0])))
	{
		grid_size++;
		bit_grid = 0;
		tab = txt_to_tab(av[1], tab, grid_size, nb_blocks[0]);
	}
	print_grid(tab, grid_size, nb_blocks[0]);
	free(tab);
	return (0);
}
