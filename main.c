/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:45:43 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/04 14:41:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		put_err(int err_code)
{
	ft_putstr("error\n");
	return (err_code);
}

static	int		gridsize(int nb_blocks)
{
	int		grid_size;

	grid_size = 2;
	while (grid_size * grid_size < nb_blocks * 4)
		grid_size++;
	return (grid_size);
}

int				main(int ac, char **av)
{
	__uint128			*tab;
	__uint128			bit_grid;
	int					nb_blocks;
	int					grid_size;

	if (ac != 2 || !(nb_blocks = is_input_valid(av[1])))
		return (put_err(0));
	grid_size = gridsize(nb_blocks);
	bit_grid = 0;
	if (!(tab = (__uint128 *)malloc(sizeof(tab[0]) * nb_blocks)))
		return (put_err(0));
	tab = txt_to_tab(av[1], tab, grid_size, nb_blocks);
	while (!(grid_insert(tab, &bit_grid, grid_size, nb_blocks)))
	{
		grid_size++;
		bit_grid = 0;
		tab = txt_to_tab(av[1], tab, grid_size, nb_blocks);
	}
	print_grid(tab, grid_size, nb_blocks);
	free(tab);
	return (0);
}
