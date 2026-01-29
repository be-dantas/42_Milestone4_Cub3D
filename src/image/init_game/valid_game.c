#include "../../../includes/cub3d.h"

// int	only_this_char(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] != '1' && line[i] != ' ')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	valid_map(t_access *ac)
// {
// 	int	i;
// 	int	j;
// 	int	len;
// 	int	len_array;

// 	i = 1;
// 	len_array = ft_strlen_array(ac->g->map) - 1;
// 	if (!only_this_char(ac->g->map[0])
// 		|| !only_this_char(ac->g->map[len_array]))
// 		return (0);
// 	while (i < len_array)
// 	{
// 		j = 1;
// 		len = ft_strlen(ac->g->map[i]) - 1;
// 		if (ac->g->map[i][0] != '1' || ac->g->map[i][len] != '1')
// 			return (0);
// 		while (j < len)
// 		{
// 			if (!ft_strchr("01NSEW ", ac->g->map[i][j]))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	valid_player(t_access *ac)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (ac->g->map[i])
	{
		j = 0;
		while (ac->g->map[i][j])
		{
			if (ac->g->map[i][j] == 'N' || ac->g->map[i][j] == 'S'
				|| ac->g->map[i][j] == 'W' || ac->g->map[i][j] == 'E')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (0);
	return (1);
}

void	valid_game(t_access *ac)
{
	if (!ac->g->tex_no || !ac->g->tex_so
		|| !ac->g->tex_we || !ac->g->tex_ea
		|| ac->g->floor_color == -1
		|| ac->g->ceiling_color == -1
		|| ac->g->flag_start_map == 0)
		error_exit(ac, "Error file map\n");
	else if (!valid_map(ac) || !valid_player(ac))
		error_exit(ac, "Error map\n");
}
