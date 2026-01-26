#include "./includes/cub3d.h"

//CRIAR UMA FLECHA QUE ESTEJA PRESA NO PIXEL(PLAYER) E GIRA 360graus EM TORNO DO PERSONAGEM APONTANDO PARA O MOUSE

int	close_window(t_access *access)
{
	if (access->img)
		mlx_destroy_image(access->mlx_connection, access->img);
	if (access->mlx_window)
		mlx_destroy_window(access->mlx_connection, access->mlx_window);
	if (access->mlx_connection)
	{
		mlx_destroy_display(access->mlx_connection);
		free(access->mlx_connection);
	}
    if (access->player)
        free(access->player);
    if (access)
        free(access);
    exit(0);
	return (0);
}

int	key_config(int keycode, void *param)
{
    t_access *access;

    access = (t_access *)param;
    if (keycode == 65307)
		close_window(access);
    if (keycode == 97)
		access->player->left = 1;
	if (keycode == 100)
		access->player->right = 1;
	if (keycode == 119)
		access->player->up = 1;
	if (keycode == 115)
		access->player->down = 1;
    // if (keycode == 65363)
    //     access->player->arrow_right = 1;
    // if (keycode == 65361)
    //     access->player->arrow_left = 1;
    return (0);
}
int key_release(int keycode, void *param)
{
    t_access    *access;

    access = (t_access *)param;
    if (keycode == 97)
		access->player->left = 0;
	if (keycode == 100)
		access->player->right = 0;
	if (keycode == 119)
		access->player->up = 0;
	if (keycode == 115)
		access->player->down = 0;
    // if (keycode == 65363)
    //     access->player->arrow_right = 0;
    // if (keycode == 65361)
    //     access->player->arrow_left = 0;
    return (0);
}
#include <stdio.h>
int action(void *param)
{
    t_access    *access;

    access = (t_access *)param;
    if (access->player->left)
		access->player->pos_x = access->player->pos_x - 0.01;
	if (access->player->right)
		access->player->pos_x = access->player->pos_x + 0.01;
	if (access->player->up)
		access->player->pos_y = access->player->pos_y - 0.01;
	if (access->player->down)
		access->player->pos_y = access->player->pos_y + 0.01;
    // if (access->player->arrow_left)
    // {
        
    // }
    // if (access->player->arrow_right)
    // {

    // }
    mlx_clear_window(access->mlx_connection, access->mlx_window);
    mlx_pixel_put(access->mlx_connection, access->mlx_window, access->player->pos_x, access->player->pos_y, 0xFFFFFF);
    return (0);
}

void game_keyboard(t_access *access)
{
    mlx_hook(access->mlx_window, 2, 1L << 0, key_config, access);//pressionando
    mlx_hook(access->mlx_window, 3, 1L << 1, key_release, access);//soltando
    mlx_loop_hook(access->mlx_connection, action, access);//acontecimento enquanto pressionado
}

void init(t_access *access)
{
    access->player = malloc(sizeof(t_player));
    access->player->pos_x = WIDTH/2;
    access->player->pos_y = HEIGHT/2;
    access->player->down = 0;
    access->player->up = 0;
    access->player->right = 0;
    access->player->left = 0;
    access->player->arrow_left = 0;
    access->player->arrow_right = 0;
    access->mlx_connection = mlx_init();
    access->mlx_window = mlx_new_window(access->mlx_connection, WIDTH, HEIGHT, "Cub3D");
    //access->img = mlx_new_image(access->mlx_connection, WIDTH, HEIGHT);
    //access->img_pointer = mlx_get_data_addr(access->img, &access->bits_per_pixel, &access->line_len, &access->endian);
}

int main(int argc, char **argv)
{
    t_access *access;
    (void)argc;
    (void)argv;

    access = malloc(sizeof(t_access));
    init(access);
    game_keyboard(access);
    mlx_loop(access->mlx_connection);
    return (0);
}