/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:03:18 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/19 14:27:57 by cormarti         ###   ########.fr       */
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

char				*trim_block(char *buf, int grid_size);
int					gridsize_modifier(char *buf, int nb_blocks);
int					smd(char *buf, int nb_blocks, int grid_size);
void				the_init(int *cnt);
int					check_init(int ac, int *nb_blocks, char *str);
int					freeturn(void *pointer, int ret);
int					put_err(int err_code);
int					get_blocks(char *file);
int					is_input_valid(char *str);
int					ft_rshift(t_uint128 *mask, size_t grid_size,
					int *nb_shift);
void				print_grid(t_uint128 *blocks, size_t grid_size,
					size_t nb_blocks);
int					grid_insert(t_uint128 *tab, t_uint128 *grid,
					int grid_size, int len);
t_uint128			block_init(t_uint128 block, size_t grid_size);
t_uint128			*txt_to_tab(char *filename, t_uint128 *tab,
					int *grid_size, int nb_blocks);

#endif
