#include "../includes/cub3d.h"

void	init_access(t_access *ac)
{
	ac->mlx_connection = mlx_init();
	ac->mlx_window = mlx_new_window(ac->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	create_image(ac);
}

void	init_player(t_access *ac)
{
	ac->p->up = 0;
	ac->p->down = 0;
	ac->p->left = 0;
	ac->p->right = 0;
	ac->p->arrow_left = 0;
	ac->p->arrow_right = 0;
	ac->p->pos_ang = 0;
	ac->p->pos_dx = cos(ac->p->pos_ang) * 0.01;
	ac->p->pos_dy = sin(ac->p->pos_ang) * 0.01;
}

int	main(int argc, char **argv)
{
	t_access	ac;
	t_game		g;
	t_player	p;

	if (argc != 2)
		return (1);
	ac.g = &g;
	ac.p = &p;
	init_game(&ac, argv[1]);
	init_access(&ac);
	init_player(&ac);
	game_keyboard(&ac);
	mlx_hook(ac.mlx_window, 17, 0, close_window, &ac);
	mlx_loop(ac.mlx_connection);
	return (0);
}
