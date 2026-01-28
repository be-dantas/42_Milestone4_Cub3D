#include "../../../includes/cub3d.h"

void	join_line_map(char *line, t_access *ac)
{
	int		i;
	int		len;
	int		len_array;
	char	**temp;

	i = 0;
	len = 0;
	len_array = ft_strlen_array(ac->g->map);
	temp = malloc(sizeof(char *) * (len_array + 2));
	if (!temp)
		error_exit(ac, "Error malloc\n");
	while (ac->g->map[i])
	{
		temp[i] = ac->g->map[i];
		i++;
	}
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	temp[i] = ft_substr(line, 0, len);
	temp[i + 1] = NULL;
	free(ac->g->map);
	ac->g->map = temp;
}

int	new_map(char *line, t_access *ac)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (line[0] == '\n')
		flag = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01NSEW ", line[i]))
			flag = 0;
		i++;
	}
	if (flag == 1)
	{
		ac->g->flag_start_map = 1;
		join_line_map(line, ac);
		return (1);
	}
	else
		return (0);
}
