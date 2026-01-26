/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:33:05 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/15 17:12:51 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	divisor_num(char *av)
{
	int	i;
	int	divisor;

	i = 0;
	divisor = 1;
	while (av[i] != '.')
		i++;
	i++;
	while (av[i])
	{
		divisor = divisor * 10;
		i++;
	}
	return (divisor);
}

void	free_split(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}

double	ft_atof(char *av)
{
	char	**split_av;
	int		atoi_av0;
	int		atoi_av1;
	int		divisor;
	int		signal;

	if (ft_is_double(av) == 0)
		return (0);
	split_av = ft_split(av, '.');
	atoi_av0 = ft_atoi(split_av[0]);
	atoi_av1 = ft_atoi(split_av[1]);
	divisor = divisor_num(av);
	signal = 1;
	if (av[0] == '-')
		signal = -1;
	free_split(split_av);
	return (((atoi_av0 + (double)atoi_av1) / divisor) * signal);
}
