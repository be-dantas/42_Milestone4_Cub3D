#include "../../includes/cub3d.h"

static void	distance_wall_xy(t_calc *calc, char **map)
{
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
}

static void	init_wall_distance_rays(t_calc *calc, t_access *ac)
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
}

static void	direction_ray_draw(t_access *ac, t_calc *calc)
{
	if (calc->ray_dx < 0)//raios indo para a esquerda (ray < 0) (indo para x (horizontal))
	{
		calc->step_x = -1;
		calc->side_dist_x = (ac->p->pos_x - calc->map_x * CUB_SIZE)
			/ fabs(calc->ray_dx);
	}
	else//raios indo para a direita (ray > 0) (indo para x (horizontal))
	{
		calc->step_x = 1;
		calc->side_dist_x = ((calc->map_x + 1) * CUB_SIZE - ac->p->pos_x)
			/ fabs(calc->ray_dx);
	}
	if (calc->ray_dy < 0)//raios indo para esquerda (ray < 0) (indo para y (vertical))
	{
		calc->step_y = -1;
		calc->side_dist_y = (ac->p->pos_y - calc->map_y * CUB_SIZE)
			/ fabs(calc->ray_dy);
	}
	else//raios indo para direita (ray > 0) (indo para y (vertical))
	{
		calc->step_y = 1;
		calc->side_dist_y = ((calc->map_y + 1) * CUB_SIZE - ac->p->pos_y)
			/ fabs(calc->ray_dy);
	}
}

void	wall_distance_rays(t_access *ac, t_calc *calc, char **map)
{
	init_wall_distance_rays(calc, ac);
	direction_ray_draw(ac, calc);
	calc->hit = 0;
	distance_wall_xy(calc, map);
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

static void	coloring_obstacles(t_access *ac, int x, int y, t_calc *calc)
{
	while (y < calc->wall_bottom)
	{
		if (calc->side == 1)
		{
			calc->px = ac->img_pointer + (y * ac->line_len
					+ x * (ac->bits_per_pixel / 8));
			*(unsigned int *)calc->px = 0x99FF9F;
		}
		else if (calc->side == 0)
		{
			calc->px = ac->img_pointer + (y * ac->line_len
					+ x * (ac->bits_per_pixel / 8));
			*(unsigned int *)calc->px = 0x9909AA;
		}
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

static void	draw_ceiling(t_access *ac)
{
	char	*px;
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			px = ac->img_pointer
				+ (y * ac->line_len + x * (ac->bits_per_pixel / 8));
			*(unsigned int *)px = ac->g->ceiling_color;
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_access *ac)
{
	char	*px;
	int		x;
	int		y;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			px = ac->img_pointer
				+ (y * ac->line_len + x * (ac->bits_per_pixel / 8));
			*(unsigned int *)px = ac->g->floor_color;
			x++;
		}
		y++;
	}
}

static void	draw_frame_floor_ceiling(t_access *ac)
{
	draw_ceiling(ac);
	draw_floor(ac);
}

void	frame_update(t_access *ac)
{
	draw_frame_floor_ceiling(ac);
	put_pixel_player(ac);
	mlx_put_image_to_window(ac->mlx_connection,
		ac->mlx_window, ac->img, 0, 0);
}
