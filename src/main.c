#include "../includes/cub3d.h"

void	init_access(t_access *ac)
{
	ac->mlx_connection = mlx_init();
	ac->mlx_window = mlx_new_window(ac->mlx_connection,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
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
	ac->p->pos_dx = cos(ac->p->pos_ang) * 0.20;
	ac->p->pos_dy = sin(ac->p->pos_ang) * 0.20;
	ac->p->shift = 0;
	ac->p->move_speed = 3;
	ac->xpm_no->img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_no, &ac->xpm_no->width, &ac->xpm_no->height);
	ac->xpm_no->img_pointer = mlx_get_data_addr(ac->xpm_no->img, &ac->xpm_no->bits_per_pixel, &ac->xpm_no->line_len, &ac->xpm_no->endian);
	ac->xpm_so->img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_so, &ac->xpm_so->width, &ac->xpm_so->height);
	ac->xpm_so->img_pointer = mlx_get_data_addr(ac->xpm_so->img, &ac->xpm_so->bits_per_pixel, &ac->xpm_so->line_len, &ac->xpm_so->endian);
	ac->xpm_ea->img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_ea, &ac->xpm_ea->width, &ac->xpm_ea->height);
	ac->xpm_ea->img_pointer = mlx_get_data_addr(ac->xpm_ea->img, &ac->xpm_ea->bits_per_pixel, &ac->xpm_ea->line_len, &ac->xpm_ea->endian);	
	ac->xpm_we->img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_we, &ac->xpm_we->width, &ac->xpm_we->height);
	ac->xpm_we->img_pointer = mlx_get_data_addr(ac->xpm_we->img, &ac->xpm_we->bits_per_pixel, &ac->xpm_we->line_len, &ac->xpm_we->endian);
}

int	main(int argc, char **argv)
{
	t_access	ac;
	t_game		g;
	t_player	p;
	t_xpm_no	xpm_no;
	t_xpm_so	xpm_so;
	t_xpm_we	xpm_we;
	t_xpm_ea	xpm_ea;
	//t_calc		calc;

	if (argc != 2)
		return (1);
	ac.g = &g;
	ac.p = &p;
	ac.xpm_no = &xpm_no;
	ac.xpm_so = &xpm_so;
	ac.xpm_we = &xpm_we;
	ac.xpm_ea = &xpm_ea;
	//ac.calc = &calc;
	init_game(&ac, argv[1]);
	init_access(&ac);
	init_player(&ac);
	game_keyboard(&ac);
	mlx_hook(ac.mlx_window, 17, 0, close_window, &ac);
	mlx_loop(ac.mlx_connection);
	return (0);
}
