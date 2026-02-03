/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:08:18 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/03 15:45:10 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_array(char **array)
{
	char	**copy;
	size_t	len_array;
	size_t	i;

	i = 0;
	len_array = ft_strlen_array(array);
	copy = malloc(sizeof(char *) * (len_array + 1));
	if (!copy)
		return (NULL);
	while (i < len_array)
	{
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			ft_free_array(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
