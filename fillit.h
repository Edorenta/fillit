/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:03:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/13 15:56:49 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define IS_INT(x) if (!x) return (0);
# define IS_CHAR(x) if (!x) return (NULL);
# define IS_VOID(x) if (!x) return ;

typedef __uint128_t			t_uint128;

int					check_init(int ac, int *nb_blocks, char *str);
int					put_err(int err_code);
int					get_blocks(char *file);
int					is_input_valid(char *str);
int					ft_rshift(t_uint128 *mask, size_t grid_size,
					int *nb_shift);
void				trim_file(char *filename, char **blocks, int nb_b);
void				print_grid(t_uint128 *blocks, size_t grid_size,
					size_t nb_blocks);
int					grid_insert(t_uint128 *tab, t_uint128 *grid,
					int grid_size, int len);
t_uint128			block_init(t_uint128 block, size_t grid_size);
t_uint128			*txt_to_tab(char *filename, t_uint128 *tab,
					int grid_size, int nb_blocks);

#endif
