#include "../../includes/cub3d.h"

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
				+ (y * ac->line_len + x * (ac->bpp / 8));
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
				+ (y * ac->line_len + x * (ac->bpp / 8));
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
