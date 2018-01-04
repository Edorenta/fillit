/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_txt_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:19:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/04 16:42:20 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	unsigned __int128	ft_pow(int x, unsigned int y)
{
	unsigned __int128	tmp;

	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if ((y % 2) == 0)
		return (tmp * tmp);
	return (x * tmp * tmp);
}

unsigned __int128			*txt_to_tab(char *filename, unsigned __int128 *tab, int grid_size,
		int nb_blocks)
{
	int		cnt[3];
	int		fd;
	char	buf[22];
	int		handle;

	fd = open(filename, O_RDONLY);
	cnt[1] = 0;
	while ((handle = read(fd, buf, 21)) > 0)
	{
		cnt[2] = 0;
		cnt[0] = -1;
		tab[cnt[1]] = 0;
		buf[handle] = '\0';
		while (buf[++cnt[0]])
			if (buf[cnt[0]] == '#')
				tab[cnt[1]] += (unsigned __int128)ft_pow(2, 127 - cnt[0] + cnt[2]);
			else if (buf[cnt[0]] == '\n')
				cnt[2] += (5 - grid_size);
		cnt[1]++;
	}
	cnt[0] = -1;
	while (++cnt[0] < nb_blocks)
		tab[cnt[0]] = block_init(tab[cnt[0]], grid_size);
	close(fd);
	return (tab);
}
