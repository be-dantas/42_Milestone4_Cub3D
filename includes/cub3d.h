#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "../src/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600
# define PI 3.1415926535

typedef struct s_player	t_player;
typedef struct s_game	t_game;

typedef struct s_game
{
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	t_player	*player;
} t_game;

typedef struct s_access
{
	void		*mlx_connection;
	void		*mlx_window;
	void		*img;
	char		*img_pointer;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	t_player	*player;
	t_game		*game;
}	t_access;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		up;
	float		down;
	float		left;
	float		right;
	float		arrow_left;
	float		arrow_right;
	float		pos_ang;
	float		pos_dx;
	float		pos_dy;
}	t_player;

// image/init_game.c
void	init_game(t_game *game, char *file);

// image/image.c
void	frame_update(t_access *access);

// movements/key.c
void	game_keyboard(t_access *access);

// movements/player_angle.c
void	right_angle(t_access *access);
void	left_angle(t_access *access);

// movements/player_mov.c
void	w_m(t_access *access);
void	s_m(t_access *access);
void	a_m(t_access *access);
void	d_m(t_access *access);

// movements/utils.c
int		close_window(t_access *access);

#endif
