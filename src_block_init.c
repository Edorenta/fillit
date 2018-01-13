/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_block_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:14:38 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/13 14:38:43 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int			eol_compliant(int i, int *j)
{
	if ((i + 1) % 21 == 0)
	{
		*j = *j + 1;
		return (1);
	}
	else if ((i + 1 - *j) % 5 == 0)
		return (1);
	return (0);
}

int					get_blocks(char *file)
{
	int		handle;
	int		cnt[2];
	char	*str;
	char	buf[1];

	cnt[0] = 0;
	cnt[1] = 0;
	if ((handle = open(file, O_RDONLY)) == -1)
		return (0);
	while ((read(handle, buf, 1)))
		if (buf[0] != '.' && buf[0] != '#' && buf[0] != '\n')
			return (0);
		else
			cnt[0]++;
	close(handle);
	IS_INT((str = (char *)malloc(sizeof(char) * (cnt[0] + 1))) || !str);
	read((handle = open(file, O_RDONLY)), str, cnt[0]);
	str[cnt[0]++] = '\0';
	close(handle);
	cnt[0] = -1;
	while (str[++cnt[0]])
		if (str[cnt[0]] == '\n' && !(eol_compliant(cnt[0], &cnt[1])))
			return (0);
	free(str);
	return (((cnt[0] + 1) % 21 == 0) ? ++cnt[1] : 0);
}

static	int			is_free_col(t_uint128 block, size_t grid_size)
{
	t_uint128	mask;
	size_t		i;

	i = 1;
	mask = 0;
	while (i <= (grid_size * grid_size))
	{
		mask |= ((t_uint128)1 << (128 - i));
		i += grid_size;
	}
	return ((block & mask) ? 0 : 1);
}

static	int			is_free_row(t_uint128 block, size_t grid_size)
{
	t_uint128	mask;
	size_t		i;

	i = 0;
	mask = 0;
	while (i < grid_size)
	{
		mask |= ((t_uint128)1 << (127 - i));
		i++;
	}
	return ((block & mask) ? 0 : 1);
}

t_uint128			block_init(t_uint128 block, size_t grid_size)
{
	while (is_free_row(block, grid_size))
		block = block << grid_size;
	while (is_free_col(block, grid_size))
		block = block << 1;
	return (block);
}
