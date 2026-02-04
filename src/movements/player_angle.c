/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:20:24 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:25 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left_angle(t_access *ac)
{
	ac->p->pos_ang -= 0.01;
	if (ac->p->pos_ang < 0)
		ac->p->pos_ang += 2 * PI;
}

void	right_angle(t_access *ac)
{
	ac->p->pos_ang += 0.01;
	if (ac->p->pos_ang > 2 * PI)
		ac->p->pos_ang -= 2 * PI;
}
