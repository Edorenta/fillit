/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:46:57 by cormarti          #+#    #+#             */
/*   Updated: 2018/01/19 13:28:45 by cormarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	the_init(int *cnt)
{
	cnt[2] = 0;
	cnt[0] = -1;
}

int		smd(char *buf, int nb_blocks, int grid_size)
{
	buf = trim_block(buf, grid_size);
	return (gridsize_modifier(buf, nb_blocks));
}
