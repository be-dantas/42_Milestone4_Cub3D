#include "../includes/cub3d.h"

void	init_access(t_access *access)
{
	access->mlx_connection = mlx_init();
	access->mlx_window = mlx_new_window(access->mlx_connection, WIDTH, HEIGHT, "Cub3D");
	access->img = mlx_new_image(access->mlx_connection, WIDTH, HEIGHT);
	access->img_pointer = mlx_get_data_addr(access->img, &access->bits_per_pixel, &access->line_len, &access->endian);
}

void	init_player(t_player *player)
{
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->arrow_left = 0;
	player->arrow_right = 0;
	player->pos_ang = 0;
	player->pos_dx = cos(player->pos_ang) * 0.01;
	player->pos_dy = sin(player->pos_ang) * 0.01;
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_access	access;
	t_player	player;

	if (argc != 2)
		return (1);
	access.player = &player;
	access.game = &game;
	game.player = &player;
	init_game(&game, argv[1]);
	//valid_game(&game);    valida e preenche a struct game com a posição x e y do player
	init_access(&access);
	init_player(&player);




	game_keyboard(&access);
	mlx_hook(access.mlx_window, 17, 0, close_window, &access);
	mlx_loop(access.mlx_connection);
	return (0);
}
