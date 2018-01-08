/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:03:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/05 13:51:29 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef	unsigned __int128 __uint128;

int					get_blocks(char *file);
int					is_input_valid(char *str);
int					ft_rshift(unsigned __int128 *mask, size_t grid_size,
					int *nb_shift);
void				print_grid(unsigned __int128 *blocks, size_t grid_size,
					size_t nb_blocks);
int					grid_insert(unsigned __int128 *tab, unsigned __int128 *grid,
					int grid_size, int len);
unsigned __int128	block_init(unsigned __int128 block, size_t grid_size);
unsigned __int128	*txt_to_tab(char *filename, unsigned __int128 *tab,
					int grid_size, int nb_blocks);

#endif
