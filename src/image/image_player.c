#include "../../includes/cub3d.h"

void	wall_distance_rays(t_access *ac, t_calc *calc, char **map)
{
	calc->ray_angle = ac->p->pos_ang
		- (FOV * PI / 180.0) / 2
		+ calc->r * ((FOV * PI / 180.0) / N_RAYS);
	calc->ray_dx = cos(calc->ray_angle);
	calc->ray_dy = sin(calc->ray_angle);
	calc->map_x = (int)(ac->p->pos_x / CUB_SIZE);
	calc->map_y = (int)(ac->p->pos_y / CUB_SIZE);
	calc->delta_dist_x = fabs(CUB_SIZE / calc->ray_dx);
	calc->delta_dist_y = fabs(CUB_SIZE / calc->ray_dy);
	if (calc->ray_dx < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (ac->p->pos_x - calc->map_x * CUB_SIZE)
			/ fabs(calc->ray_dx);
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = ((calc->map_x + 1) * CUB_SIZE - ac->p->pos_x)
			/ fabs(calc->ray_dx);
	}
	if (calc->ray_dy < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (ac->p->pos_y - calc->map_y * CUB_SIZE)
			/ fabs(calc->ray_dy);
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = ((calc->map_y + 1) * CUB_SIZE - ac->p->pos_y)
			/ fabs(calc->ray_dy);
	}
	calc->hit = 0;
	while (!calc->hit)
	{
		if (calc->side_dist_x < calc->side_dist_y)
		{
			calc->side_dist_x += calc->delta_dist_x;
			calc->map_x += calc->step_x;
			calc->side = 0; // vertical wall
		}
		else
		{
			calc->side_dist_y += calc->delta_dist_y;
			calc->map_y += calc->step_y;
			calc->side = 1; // horizontal wall
		}
		if (map[calc->map_y][calc->map_x] == '1')
			calc->hit = 1;
	}
	if (calc->side == 0)
		calc->dist = calc->side_dist_x - calc->delta_dist_x;
	else
		calc->dist = calc->side_dist_y - calc->delta_dist_y;
	calc->angle_diff = calc->ray_angle - ac->p->pos_ang;
	calc->dist = calc->dist * cos(calc->angle_diff);

}

void	wall_perspective_calc(t_calc *calc)
{
	calc->wall_height = (CUB_SIZE * SCREEN_HEIGHT) / calc->dist;
	calc->wall_top = (SCREEN_HEIGHT / 2) - (calc->wall_height / 2);
	calc->wall_bottom = (SCREEN_HEIGHT / 2) + (calc->wall_height / 2);
	if (calc->wall_top < 0)
		calc->wall_top = 0;
	if (calc->wall_bottom >= SCREEN_HEIGHT)
		calc->wall_bottom = SCREEN_HEIGHT - 1;
	calc->column_width = SCREEN_WIDTH / N_RAYS;
	if (calc->column_width < 1)
		calc->column_width = 1;
	calc->column_x = calc->r * calc->column_width;
}

void	draw_obstacles(t_access *ac, t_calc *calc)
{
	int		x;
	int		y;

	x = calc->column_x;
	y = calc->wall_top;

	while (x < calc->column_x + calc->column_width)
	{
		if (x < 0 || x >= SCREEN_WIDTH)
		{
			x++;
			continue ;
		}
		while (y < calc->wall_bottom)
		{
			if (calc->side == 1)
			{
				calc->px = ac->img_pointer
					+ (y * ac->line_len
						+ x * (ac->bits_per_pixel / 8));
				*(unsigned int *)calc->px = 0x99FF9F;
			}
			else if (calc->side == 0)
			{
				calc->px = ac->img_pointer
					+ (y * ac->line_len
						+ x * (ac->bits_per_pixel / 8));
				*(unsigned int *)calc->px = 0x9909AA;
			}
			y++;
		}
		x++;
	}
}

void	put_pixel_player(t_access *ac)
{
	char	**map;
	t_calc	calc;

	map = ac->g->map;
	calc.r = 0;
	while (calc.r < N_RAYS)
	{
		wall_distance_rays(ac, &calc, map);
		wall_perspective_calc(&calc);
		draw_obstacles(ac, &calc);
		calc.r++;
	}
}


void	frame_update(t_access *ac)
{
	char *px;

	int xxx = 0;
	int yyy = 0;
	while (yyy < SCREEN_HEIGHT / 2)
	{
		xxx = 0;
		while (xxx < SCREEN_WIDTH)
		{
			px = ac->img_pointer
				+ (yyy * ac->line_len
					+ xxx * (ac->bits_per_pixel / 8));
			*(unsigned int *)px = ac->g->ceiling_color;
			xxx++;
		}
		yyy++;
	}
	yyy = SCREEN_HEIGHT / 2;
	while (yyy < SCREEN_HEIGHT)
	{
		xxx = 0;
		while (xxx < SCREEN_WIDTH)
		{
			px = ac->img_pointer
				+ (yyy * ac->line_len
					+ xxx * (ac->bits_per_pixel / 8));
			*(unsigned int *)px = ac->g->floor_color;
			xxx++;
		}
		yyy++;
	}
	put_pixel_player(ac);
	mlx_put_image_to_window(ac->mlx_connection,
		ac->mlx_window, ac->img, 0, 0);
}
