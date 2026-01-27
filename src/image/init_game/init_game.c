#include "../../../includes/cub3d.h"

// game->tex_no = //linha 1
// game->tex_so = //linha 2
// game->tex_we = //linha 3
// game->tex_ea = //linha 4
// game->floor_color = //linha 5 (chao)
// game->ceiling_color = //linha 6 (teto)
// game->map = 
// game->player->pos_x = 
// game->player->pos_y = 

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
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

int	trate_color(char *color, t_game *game)
{
	int		result;
	char	**split_color;
	int		r;
	int		g;
	int 	b;

	split_color = ft_split(color, ',');
	if (!split_color)
		error_exit(game, "Error malloc");
	if (ft_strlen_array(split_color) != 3)
		error_exit(game, "Error file map");
	r = ft_atoi(split_color[0]);
	g = ft_atoi(split_color[1]);
	b = ft_atoi(split_color[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		ft_free_array(split_color);
		error_exit(game, "Error file map");
	}
	ft_free_array(split_color);
	return (r << 16 | g << 8 | b);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("01NSEW ", line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	join_line_map(char *line, t_game *game)
{
	int		i;
	int		len_array;
	char	**temp;

	i = 0;
	len_array = ft_strlen_array(game->map);
	temp = malloc(sizeof(char *) * (len_array + 2));
	if (!temp)
		error_exit(game, "Error malloc");
	while (game->map[i])
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	temp[i + 1] = NULL;
	ft_free_array(game->map);
	game->map = temp;
}

void	new_variable(char *line, t_game *game)
{
	char	*temp;

	temp = NULL;
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->tex_no = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->tex_so = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->tex_we = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->tex_ea = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		temp = ft_substr(line, 2, ft_strlen(line) - 3);
		game->floor_color = trate_color(temp, game);
		free(temp);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		temp = ft_substr(line, 2, ft_strlen(line) - 3);
		game->ceiling_color = trate_color(temp, game);
		free(temp);
	}
	else if (is_map_line(line))
		join_line_map(line, game);
	else
		error_exit(game, "Error file map");
}

void	init_game(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("");
	while ((line = get_next_line(fd)))
	{
		new_variable(line, game);
		free(line);
	}
	close(fd);
}
