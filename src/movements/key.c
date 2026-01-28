#include "../../includes/cub3d.h"

void	create_image(t_access *ac)
{
	ac->img = mlx_new_image(
			ac->mlx_connection,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	ac->img_pointer = mlx_get_data_addr(
			ac->img,
			&ac->bits_per_pixel,
			&ac->line_len,
			&ac->endian);
}

int	key_config(int keycode, void *param)
{
	t_access	*ac;

	ac = (t_access *)param;
	if (keycode == 65307)
		close_window(ac);
	if (keycode == 97)
		ac->p->left = 1;
	if (keycode == 100)
		ac->p->right = 1;
	if (keycode == 119)
		ac->p->up = 1;
	if (keycode == 115)
		ac->p->down = 1;
	if (keycode == 65363)
		ac->p->arrow_right = 1;
	if (keycode == 65361)
		ac->p->arrow_left = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_access	*ac;

	ac = (t_access *)param;
	if (keycode == 97)
		ac->p->left = 0;
	if (keycode == 100)
		ac->p->right = 0;
	if (keycode == 119)
		ac->p->up = 0;
	if (keycode == 115)
		ac->p->down = 0;
	if (keycode == 65363)
		ac->p->arrow_right = 0;
	if (keycode == 65361)
		ac->p->arrow_left = 0;
	return (0);
}

int	action(void *param)
{
	t_access	*ac;

	ac = (t_access *)param;
	if (ac->p->arrow_left)
		left_angle(ac);
	if (ac->p->arrow_right)
		right_angle(ac);
	ac->p->pos_dx = cos(ac->p->pos_ang) * 0.1;
	ac->p->pos_dy = sin(ac->p->pos_ang) * 0.1;
	if (ac->p->up)
		w_m(ac);
	if (ac->p->down)
		s_m(ac);
	if (ac->p->left)
		a_m(ac);
	if (ac->p->right)
		d_m(ac);
	mlx_destroy_image(ac->mlx_connection, ac->img);
	create_image(ac);
	frame_update(ac);
	return (0);
}

void	game_keyboard(t_access *ac)
{
	mlx_hook(ac->mlx_window, 2, 1L << 0, key_config, ac);
	mlx_hook(ac->mlx_window, 3, 1L << 1, key_release, ac);
	mlx_loop_hook(ac->mlx_connection, action, ac);
}
