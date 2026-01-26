#include "../../includes/cub3d.h"

void	w_m(t_access *access)
{
	access->player->pos_x += access->player->pos_dx;
	access->player->pos_y += access->player->pos_dy;
}

void	s_m(t_access *access)
{
	access->player->pos_x -= access->player->pos_dx;
	access->player->pos_y -= access->player->pos_dy;
}

void	a_m(t_access *access)
{
	access->player->pos_x += access->player->pos_dy;
	access->player->pos_y -= access->player->pos_dx;
}

void	d_m(t_access *access)
{
	access->player->pos_x -= access->player->pos_dy;
	access->player->pos_y += access->player->pos_dx;
}
