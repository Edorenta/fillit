/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_txt_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:19:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/13 17:55:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_uint128	ft_pow(int x, unsigned int y)
{
	t_uint128	tmp;

	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if ((y % 2) == 0)
		return (tmp * tmp);
	return (x * tmp * tmp);
}

static	char		*str_shift(char *bk, int shift)
{
	int i;

	i = -1;
	while (++i < 22)
	{
		if (bk[i] != '\n' && bk[i + shift] != '\n')
			bk[i] = bk[i + shift];
		if ((i % 5) >= (5 - shift - 1) && bk[i] != '\n')
			bk[i] = '.';
	}
	return (bk);
}

void				trim_file(char *filename, char **bk, int nb_b)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	IS_VOID((str = (char *)malloc(sizeof(char) * (25 * nb_b))));
	fd = open(filename, O_RDWR);
	while (++i < nb_b)
	{
		j = 0;
		while (j < 5 && bk[i][j] == '.' && bk[i][j + 5] == '.'
				&& bk[i][j + 10] == '.' && bk[i][j + 15] == '.')
			j++;
		bk[i] = (j > 0 ? str_shift(bk[i], j) : bk[i]);
		str = ft_strcat(str, bk[i]);
	}
	write(fd, str, ft_strlen(str) - 1);
	free(str);
	close(fd);
}

t_uint128			*txt_to_tab(char *filename, t_uint128 *tab, int grid_size,
		int nb_blockslocks)
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
				tab[cnt[1]] += (t_uint128)ft_pow(2, 127 - cnt[0] + cnt[2]);
			else if (buf[cnt[0]] == '\n')
				cnt[2] += (5 - grid_size);
		cnt[1]++;
	}
	cnt[0] = -1;
	while (++cnt[0] < nb_blockslocks)
		tab[cnt[0]] = block_init(tab[cnt[0]], grid_size);
	close(fd);
	return (tab);
}
