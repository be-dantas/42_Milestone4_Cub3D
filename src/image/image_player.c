#include "../../includes/cub3d.h"

void	wall_distance_rays(t_access *ac, t_calc *calc, char **map)
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;

	// 1️⃣ Ray angle & direction
	calc->ray_angle = ac->p->pos_ang
		- (FOV * PI / 180.0) / 2
		+ calc->r * ((FOV * PI / 180.0) / N_RAYS);

	calc->ray_dx = cos(calc->ray_angle);
	calc->ray_dy = sin(calc->ray_angle);

	// 2️⃣ Player position in map coordinates
	calc->map_x = (int)(ac->p->pos_x / CUB_SIZE);
	calc->map_y = (int)(ac->p->pos_y / CUB_SIZE);

	// 3️⃣ Distance to next grid line
	delta_dist_x = fabs(CUB_SIZE / calc->ray_dx);
	delta_dist_y = fabs(CUB_SIZE / calc->ray_dy);

	// 4️⃣ Step direction and initial side distances
	if (calc->ray_dx < 0)
	{
		step_x = -1;
		side_dist_x = (ac->p->pos_x - calc->map_x * CUB_SIZE)
			/ fabs(calc->ray_dx);
	}
	else
	{
		step_x = 1;
		side_dist_x = ((calc->map_x + 1) * CUB_SIZE - ac->p->pos_x)
			/ fabs(calc->ray_dx);
	}

	if (calc->ray_dy < 0)
	{
		step_y = -1;
		side_dist_y = (ac->p->pos_y - calc->map_y * CUB_SIZE)
			/ fabs(calc->ray_dy);
	}
	else
	{
		step_y = 1;
		side_dist_y = ((calc->map_y + 1) * CUB_SIZE - ac->p->pos_y)
			/ fabs(calc->ray_dy);
	}

	// 5️⃣ DDA loop
	hit = 0;
	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			calc->map_x += step_x;
			calc->side = 0; // vertical wall
		}
		else
		{
			side_dist_y += delta_dist_y;
			calc->map_y += step_y;
			calc->side = 1; // horizontal wall
		}
		if (map[calc->map_y][calc->map_x] == '1')
			hit = 1;
	}

	// 6️⃣ Final perpendicular distance (NO fisheye)
	if (calc->side == 0)
		calc->dist = side_dist_x - delta_dist_x;
	else
		calc->dist = side_dist_y - delta_dist_y;
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
			calc->px = ac->img_pointer
				+ (y * ac->line_len
					+ x * (ac->bits_per_pixel / 8));
			*(unsigned int *)calc->px = 0x99FF9F;
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
	put_pixel_player(ac);
	mlx_put_image_to_window(ac->mlx_connection,
		ac->mlx_window, ac->img, 0, 0);
}
