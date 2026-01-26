#include "../../includes/cub3d.h"

void	left_angle(t_access *access)
{
	access->player->pos_ang -= 0.01;
	if (access->player->pos_ang < 0)
		access->player->pos_ang += 2 * PI;
}

void	right_angle(t_access *access)
{
	access->player->pos_ang += 0.01;
	if (access->player->pos_ang > 2 * PI)
		access->player->pos_ang -= 2 * PI;
}
