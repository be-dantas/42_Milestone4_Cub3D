/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:33:05 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/16 10:10:05 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_double(char *av)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if ((av[i] == '+' && ft_isdigit(av[i + 1]))
		|| (av[i] == '-' && ft_isdigit(av[i + 1])))
		i++;
	while (av[i])
	{
		if (av[i] == '.')
			dot_count++;
		if (ft_isdigit(av[i]) || av[i] == '.')
			i++;
		else
			return (0);
	}
	if (dot_count > 1)
		return (0);
	if (av[0] == '.' || av[i - 1] == '.')
		return (0);
	if (dot_count == 0)
		return (1);
	return (2);
}
