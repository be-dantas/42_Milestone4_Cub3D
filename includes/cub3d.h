#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "../src/gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800
# define PI 3.1415926535
# define FOV 60
# define N_RAYS 1000
# define CUB_SIZE 64

typedef struct s_player	t_player;
typedef struct s_access t_access;
typedef struct s_calc 	t_calc;

typedef struct s_game
{
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			flag_start_map;
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
	t_calc		*calc;
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

typedef struct s_calc
{
	char		*px;
	int			r;
	double		ray_angle;
	double		ray_dx;
	double		ray_dy;
	double		xx;
	double		yy;
	double		dist;
	int			map_x;
	int			map_y;
	double		wall_height;
	int			wall_top;
	int			wall_bottom;
	int			column_width;
	int			column_x;
}	t_calc;

// image/init_game
void	error_exit(t_game *game, char *str);
void	init_game(t_game *game, char *file);
int		new_tex(char *line, t_game *game);
int		new_color(char *line, t_game *game);
int		new_map(char *line, t_game *game);
int		valid_game(t_game *game);

// image/draw_map.c
void	draw_map(char **map, int i, int j, t_access *access);

// image/image_player.c
void	frame_update(t_access *access);

// movements/key.c
void	create_image(t_access *access);
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
