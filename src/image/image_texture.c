/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:20:14 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:15 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	pos_ray_find_wall(t_access *ac, t_calc *calc)
{
	if (calc->side == 1)
		calc->wall_x = ac->p->pos_x / CUB_SIZE
			+ calc->raw_dist * calc->ray_dx / CUB_SIZE;
	else
		calc->wall_x = ac->p->pos_y / CUB_SIZE
			+ calc->raw_dist * calc->ray_dy / CUB_SIZE;
	calc->wall_x -= floor(calc->wall_x);
}

static void	coloring_obstacles(t_access *ac, int x, int y, t_calc *calc)
{
	int		d;
	int		color;

	pos_ray_find_wall(ac, calc);
	while (y < calc->wall_bottom)
	{
		d = y * 256 - SCREEN_HEIGHT * 128 + calc->wall_height * 128;
		if (calc->side == 1)
		{
			if (calc->ray_dy > 0)
				color = coloring_so(ac, calc, d);
			else
				color = coloring_no(ac, calc, d);
		}
		else
		{
			if (calc->ray_dx > 0)
				color = coloring_ea(ac, calc, d);
			else
				color = coloring_we(ac, calc, d);
		}
		calc->px = ac->img_pointer + y * ac->line_len + x * (ac->bpp / 8);
		*(int *)calc->px = color;
		y++;
	}
}

void	draw_obstacles(t_access *ac, t_calc *calc)
{
	int		x;
	int		y;

	x = calc->column_x;
	while (x < calc->column_x + calc->column_width)
	{
		y = calc->wall_top;
		if (x < 0 || x >= SCREEN_WIDTH)
		{
			x++;
			continue ;
		}
		coloring_obstacles(ac, x, y, calc);
		x++;
	}
}
