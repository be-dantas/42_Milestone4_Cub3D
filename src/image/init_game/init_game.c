#include "../../../includes/cub3d.h"

void	error_exit(t_game *game, char *str)
{
	if (game->tex_no)
		free(game->tex_no);
	if (game->tex_so)
		free(game->tex_so);
	if (game->tex_we)
		free(game->tex_we);
	if (game->tex_ea)
		free(game->tex_ea);
	if (game->map)
		ft_free_array(game->map);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	new_variable(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Error opening file\n");
	while ((line = get_next_line(fd)))
	{
		if (empty_line(line))
		{
			if (game->flag_start_map)
				error_exit(game, "Error file map\n");
		}
		else
		{
			if (!new_tex(line, game) && !new_color(line, game) && !new_map(line, game))
				error_exit(game, "Error file map\n");
		}
		free(line);
	}
	close(fd);
}

void	new_pos_x_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (!ft_strchr("NSEW", game->map[i][j]))
			j++;
		if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
			|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			break ;
		i++;
	}
	game->player->pos_x = j * 64;
	game->player->pos_y = i * 64;
}

void	init_game(t_game *game, char *file)
{
	game->tex_no = NULL;
	game->tex_so = NULL;
	game->tex_we = NULL;
	game->tex_ea = NULL;
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->map = ft_calloc(1, sizeof(char *));
	game->flag_start_map = 0;
	new_variable(game, file);
	// valid_game(game);
	new_pos_x_y(game);



	// printf("%s\n", game->tex_no);
	// printf("%s\n", game->tex_so);
	// printf("%s\n", game->tex_we);
	// printf("%s\n", game->tex_ea);
	// printf("%d\n", game->floor_color);
	// printf("%d\n", game->ceiling_color);
	// int i = 0;
	// while (game->map[i])
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
}
