#include "../../includes/cub3d.h"

void game_keyboard(t_access *access)
{
    mlx_hook(access->mlx_window, 2, 1L << 0, key_config, access);
    mlx_hook(access->mlx_window, 3, 1L << 1, key_release, access);
    mlx_loop_hook(access->mlx_connection, action, access);
}

int action(void *param)
{
    t_access    *access;

    access = (t_access *)param;
    if (access->player->arrow_left)
            left_angle(access);
    if (access->player->arrow_right)
            right_angle(access);
    access->player->pos_dx = cos(access->player->pos_ang) * 0.1;
    access->player->pos_dy = sin(access->player->pos_ang) * 0.1;
	if (access->player->up)
            w_m(access);
	if (access->player->down)
            s_m(access);
    if (access->player->left)
            a_m(access);
	if (access->player->right)
            d_m(access);
    frame_update(access);
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
    if (keycode == 65363)
        access->player->arrow_right = 1;
    if (keycode == 65361)
        access->player->arrow_left = 1;
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
    if (keycode == 65363)
        access->player->arrow_right = 0;
    if (keycode == 65361)
        access->player->arrow_left = 0;
    return (0);
}