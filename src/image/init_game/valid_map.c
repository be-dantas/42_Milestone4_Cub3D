/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:20:01 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:02 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_open(char **map, int i, int j)
{
	if (i < 0 || !map[i])
		return (1);
	if (j < 0 || j >= (int)ft_strlen(map[i]))
		return (1);
	if (map[i][j] == ' ')
		return (1);
	return (0);
}

static int	check_cell(char **map, int i, int j)
{
	if (!ft_strchr("0NSEW", map[i][j]))
		return (1);
	if (is_open(map, i - 1, j)
		|| is_open(map, i + 1, j)
		|| is_open(map, i, j - 1)
		|| is_open(map, i, j + 1)
		|| is_open(map, i - 1, j - 1)
		|| is_open(map, i - 1, j + 1)
		|| is_open(map, i + 1, j - 1)
		|| is_open(map, i + 1, j + 1))
		return (0);
	return (1);
}

static int	only_this_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid_map(char **map)
{
	int	i;
	int	j;
	int	len;
	int	len_array;

	i = 1;
	len_array = ft_strlen_array(map) - 1;
	if (!only_this_char(map[0])
		|| !only_this_char(map[len_array]))
		return (0);
	while (i < len_array)
	{
		j = 1;
		len = ft_strlen(map[i]) - 1;
		if (map[i][0] != '1' || map[i][len] != '1')
			return (0);
		while (j < len)
		{
			if (!check_cell(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
