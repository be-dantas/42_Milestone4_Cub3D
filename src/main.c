/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:20:34 by bedantas          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:35 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	error_xpm(t_access *ac, char *str)
{
	if (ac->xpm_no.img)
		mlx_destroy_image(ac->mlx_connection, ac->xpm_no.img);
	if (ac->xpm_so.img)
		mlx_destroy_image(ac->mlx_connection, ac->xpm_so.img);
	if (ac->xpm_ea.img)
		mlx_destroy_image(ac->mlx_connection, ac->xpm_ea.img);
	if (ac->xpm_we.img)
		mlx_destroy_image(ac->mlx_connection, ac->xpm_we.img);
	if (ac->img)
		mlx_destroy_image(ac->mlx_connection, ac->img);
	if (ac->mlx_window)
		mlx_destroy_window(ac->mlx_connection, ac->mlx_window);
	if (ac->mlx_connection)
	{
		mlx_destroy_display(ac->mlx_connection);
		free(ac->mlx_connection);
	}
	free_close_window(ac);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void	init_xpm(t_access *ac)
{
	ac->xpm_no.img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_no,
			&ac->xpm_no.width, &ac->xpm_no.height);
	if (ac->xpm_no.img == NULL)
		error_xpm(ac, "Error file texture\n");
	ac->xpm_no.img_pointer = mlx_get_data_addr(ac->xpm_no.img,
			&ac->xpm_no.bpp, &ac->xpm_no.line_len, &ac->xpm_no.endian);
	ac->xpm_so.img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_so,
			&ac->xpm_so.width, &ac->xpm_so.height);
	if (ac->xpm_so.img == NULL)
		error_xpm(ac, "Error file texture\n");
	ac->xpm_so.img_pointer = mlx_get_data_addr(ac->xpm_so.img,
			&ac->xpm_so.bpp, &ac->xpm_so.line_len, &ac->xpm_so.endian);
	ac->xpm_ea.img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_ea,
			&ac->xpm_ea.width, &ac->xpm_ea.height);
	if (ac->xpm_ea.img == NULL)
		error_xpm(ac, "Error file texture\n");
	ac->xpm_ea.img_pointer = mlx_get_data_addr(ac->xpm_ea.img,
			&ac->xpm_ea.bpp, &ac->xpm_ea.line_len, &ac->xpm_ea.endian);
	ac->xpm_we.img = mlx_xpm_file_to_image(ac->mlx_connection, ac->g->tex_we,
			&ac->xpm_we.width, &ac->xpm_we.height);
	if (ac->xpm_we.img == NULL)
		error_xpm(ac, "Error file texture\n");
	ac->xpm_we.img_pointer = mlx_get_data_addr(ac->xpm_we.img,
			&ac->xpm_we.bpp, &ac->xpm_we.line_len, &ac->xpm_we.endian);
}

static void	init_access(t_access *ac)
{
	ac->mlx_window = mlx_new_window(ac->mlx_connection,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!ac->mlx_window)
		error_xpm(ac, "Error mlx window\n");
	create_image(ac);
	if (!ac->img)
		error_xpm(ac, "Error image creation\n");
}

static void	init_player(t_access *ac)
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
}

int	main(int argc, char **argv)
{
	t_access	ac;
	t_game		g;
	t_player	p;

	ft_bzero(&ac, sizeof(t_access));
	ft_bzero(&p, sizeof(t_access));
	ft_bzero(&g, sizeof(t_access));
	if (argc != 2)
		return (1);
	ac.g = &g;
	ac.p = &p;
	ac.mlx_connection = mlx_init();
	if (!ac.mlx_connection)
		error_xpm(&ac, "Error mlx init\n");
	init_game(&ac, argv[1]);
	init_xpm(&ac);
	init_access(&ac);
	init_player(&ac);
	game_keyboard(&ac);
	mlx_hook(ac.mlx_window, 17, 0, close_window, &ac);
	mlx_loop(ac.mlx_connection);
	return (0);
}
