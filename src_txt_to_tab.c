/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_txt_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:19:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/19 13:10:47 by cormarti         ###   ########.fr       */
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

static	char		*str_shift(char *buf, int shift, int index, int grid_size)
{
	int i;

	i = -1;
	if (index == 1)
		while (++i < 22)
		{
			if (buf[i] != '\n' && buf[i + shift] != '\n')
				buf[i] = buf[i + shift];
			if ((i % 5) >= (5 - shift - 1) && buf[i] != '\n')
				buf[i] = '.';
		}
	else if (index == 2 && grid_size < 4)
	{
		while (buf[++i + shift] != '\0')
		{
			if (buf[i + shift] == '#')
			{
				buf[i] = buf[i + shift];
				buf[i + shift] = '.';
			}
		}
	}
	return (buf);
}

int					gridsize_modifier(char *buf, int nb_blocks)
{
	if ((buf[0] == '#' && buf[1] == '#' && buf[2] == '#' && buf[3] == '#')
		|| (buf[5] == '#' && buf[6] == '#' && buf[7] == '#' && buf[8] == '#')
		|| (buf[10] == '#' && buf[11] == '#' && buf[12] == '#'
			&& buf[13] == '#')
		|| (buf[15] == '#' && buf[15] == '#' && buf[16] == '#'
			&& buf[17] == '#')
		|| (buf[0] == '#' && buf[5] == '#' && buf[10] == '#' && buf[15] == '#'))
		return (4);
	if (nb_blocks == 1
		&& ((buf[0] == '#' && buf[1] == '#' && buf[5] == '#' && buf[6] == '#')
		|| (buf[5] == '#' && buf[6] == '#' && buf[10] == '#' && buf[11] == '#')
		|| (buf[10] == '#' && buf[11] == '#' && buf[15] == '#'
			&& buf[16] == '#')))
		return (2);
	return (3);
}

char				*trim_block(char *buf, int grid_size)
{
	int		i;

	i = 0;
	while (i < 5 && buf[i] == '.' && buf[i + 5] == '.'
			&& buf[i + 10] == '.' && buf[i + 15] == '.')
		i++;
	buf = i > 0 ? str_shift(buf, i, 1, grid_size) : buf;
	i = 0;
	while (i < 21 && buf[i] == '.' && buf[i + 1] == '.'
			&& buf[i + 2] == '.' && buf[i + 3] == '.')
		i += 5;
	buf = i > 0 ? str_shift(buf, i, 2, grid_size) : buf;
	return (buf);
}

t_uint128			*txt_to_tab(char *filename, t_uint128 *tab, int *gs,
		int nb_blocks)
{
	int		cnt[3];
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	IS_INT((buf = (char *)malloc(sizeof(char) * (22))));
	cnt[1] = -1;
	while ((read(fd, buf, 21)) > 0 && (++cnt[1] < nb_blocks))
	{
		buf[21] = '\0';
		*gs = *gs == 3 ? smd(buf, nb_blocks, *gs) : *gs;
		the_init(cnt);
		tab[cnt[1]] = 0;
		while (buf[++cnt[0]])
			if (buf[cnt[0]] == '#')
				tab[cnt[1]] += (t_uint128)ft_pow(2, 127 - cnt[0] + cnt[2]);
			else if (buf[cnt[0]] == '\n')
				cnt[2] += (5 - *gs);
	}
	free(buf);
	cnt[0] = -1;
	while (++cnt[0] < nb_blocks)
		tab[cnt[0]] = block_init(tab[cnt[0]], *gs);
	close(fd);
	return (tab);
}
