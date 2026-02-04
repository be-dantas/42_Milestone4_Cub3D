/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:20:27 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:28 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	w_m(t_access *ac)
{
	int		check_x;
	int		check_y;
	double	next_x;
	double	next_y;

	next_x = ac->p->pos_x + ac->p->pos_dx * ac->p->move_speed;
	next_y = ac->p->pos_y + ac->p->pos_dy * ac->p->move_speed;
	check_x = (int)(next_x / 64);
	check_y = (int)(next_y / 64);
	if (ac->g->map[check_y][check_x] != '1')
	{
		ac->p->pos_x = next_x;
		ac->p->pos_y = next_y;
	}
}

void	s_m(t_access *ac)
{
	int		check_x;
	int		check_y;
	double	next_x;
	double	next_y;

	next_x = ac->p->pos_x - ac->p->pos_dx * ac->p->move_speed;
	next_y = ac->p->pos_y - ac->p->pos_dy * ac->p->move_speed;
	check_x = (int)(next_x / 64);
	check_y = (int)(next_y / 64);
	if (ac->g->map[check_y][check_x] != '1')
	{	
		ac->p->pos_x = next_x;
		ac->p->pos_y = next_y;
	}
}

void	a_m(t_access *ac)
{
	int		check_x;
	int		check_y;
	double	next_x;
	double	next_y;

	next_x = ac->p->pos_x + ac->p->pos_dy * ac->p->move_speed;
	next_y = ac->p->pos_y - ac->p->pos_dx * ac->p->move_speed;
	check_x = (int)(next_x / 64);
	check_y = (int)(next_y / 64);
	if (ac->g->map[check_y][check_x] != '1')
	{
		ac->p->pos_x = next_x;
		ac->p->pos_y = next_y;
	}
}

void	d_m(t_access *ac)
{
	int		check_x;
	int		check_y;
	double	next_x;
	double	next_y;

	next_x = ac->p->pos_x - ac->p->pos_dy * ac->p->move_speed;
	next_y = ac->p->pos_y + ac->p->pos_dx * ac->p->move_speed;
	check_x = (int)(next_x / 64);
	check_y = (int)(next_y / 64);
	if (ac->g->map[check_y][check_x] != '1')
	{
		ac->p->pos_x = next_x;
		ac->p->pos_y = next_y;
	}
}
