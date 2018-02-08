/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:59:02 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/18 17:41:23 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		freeturn(void *pointer, int ret)
{
	free(pointer);
	return (ret);
}

int		check_init(int ac, int *nb_blocks, char *str)
{
	if (ac == 1 || ac > 2)
		return (2);
	else if (!(*nb_blocks = is_input_valid(str)) || nb_blocks[0] > 26)
		return (1);
	return (0);
}

int		put_err(int err_code)
{
	if (err_code == 1)
		ft_putstr("error\n");
	else if (err_code == 2)
		ft_putstr("usage: ./fillit test_file\n");
	return (0);
}
