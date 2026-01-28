#include "../../includes/cub3d.h"

void	wall_distance_rays(t_access *access, t_calc *calc, char **map)
{
	calc->ray_angle = access->player->pos_ang
		- (FOV * PI / 180.0) / 2 + calc->r * ((FOV * PI / 180.0) / N_RAYS);
	calc->ray_dx = cos(calc->ray_angle);
	calc->ray_dy = sin(calc->ray_angle);
	calc->xx = access->player->pos_x;
	calc->yy = access->player->pos_y;
	while (1)
	{
		calc->map_x = (int)(calc->xx / CUB_SIZE);
		calc->map_y = (int)(calc->yy / CUB_SIZE);
		if (map[calc->map_y][calc->map_x] == '1')
			break ;
		calc->xx += calc->ray_dx;
		calc->yy += calc->ray_dy;
	}
	calc->dist = sqrt(
		(calc->xx - access->player->pos_x) * (calc->xx - access->player->pos_x) +
		(calc->yy - access->player->pos_y) * (calc->yy - access->player->pos_y)
	);
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

void	draw_obstacles(t_access *access, t_calc *calc)
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
			continue;
		}
		while(y < calc->wall_bottom)
		{
			calc->px = access->img_pointer
				+ (y * access->line_len
				+ x * (access->bits_per_pixel / 8));
			*(unsigned int *)calc->px = 0x99FF9F;
			y++;
		}
		x++;
	}
}

void	put_pixel_player(t_access *access)
{
	access->calc = malloc(sizeof(t_calc));
	t_calc *calc = access->calc;
	char **map;

	map = access->game->map;
	calc->r = 0;
	while (calc->r < N_RAYS)
	{
		wall_distance_rays(access, calc, map);
		wall_perspective_calc(calc);
		draw_obstacles(access, calc);
		calc->r++;
	}
}

void	frame_update(t_access *access)
{
	put_pixel_player(access);
	mlx_put_image_to_window(access->mlx_connection,
		access->mlx_window, access->img, 0, 0);
}
