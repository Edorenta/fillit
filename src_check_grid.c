/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_check_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:16:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/04 14:52:27 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**input_reader(char *file, int hypo_blocks)
{
	int		fd;
	int		i;
	int		handle;
	char	buf[22];
	char	**output;

	i = -1;
	if (!(output = (char **)malloc(sizeof(char *) * hypo_blocks)))
		return (NULL);
	while (++i < hypo_blocks)
		output[i] = (char *)malloc(sizeof(char) * 22);
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((hypo_blocks >= i) && (handle = read(fd, buf, 21)))
	{
		output[i] = ft_strcpy(output[i], buf);
		i++;
	}
	return (output);
}

static	int		block_check(char *str)
{
	int i;
	int hashtag;
	int point;
	int endl;

	i = -1;
	hashtag = 0;
	point = 0;
	endl = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
			hashtag++;
		else if (str[i] == '.')
			point++;
		else if (str[i] == '\n')
			endl++;
		else if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
	}
	return ((hashtag != 4 || point != 12 || endl != 4) ? 0 : (endl / 4));
}

static	int		integrity_check(char *str)
{
	int		touch;
	int		i;

	touch = 0;
	i = -1;
	while (++i < 20)
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				touch++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				touch++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				touch++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				touch++;
		}
	return (touch == 6 || touch == 8);
}

static	int		input_check(char **str, int hypo_blocks)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (++i < (hypo_blocks))
		if (!block_check(str[i]) || !integrity_check(str[i]))
			return (0);
	return (1);
}

int				is_input_valid(char *str)
{
	int		res;
	int		i;
	int		hypo_blocks;
	char	**input;

	i = -1;
	if ((hypo_blocks = get_blocks(str)) == 0)
		return (0);
	input = input_reader(str, hypo_blocks);
	res = input_check(input, hypo_blocks);
	while (++i <= hypo_blocks)
		free(input[i]);
	free(input);
	return ((!res) ? 0 : hypo_blocks);
}
