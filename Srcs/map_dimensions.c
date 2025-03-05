/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:34:04 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	handle_fd_error(t_params *var, int fd, char *msg)
{
	if (fd == -1)
	{
		exit_on_error(var, msg);
		close (fd);
	}
}

void	ft_print_ascii_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		printf("%d ", (int)line[i]);
		i++;
	}
	printf(" : ok\n");
}

bool	ft_is_single_char(char *line, char c)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0 || c == 0)
		return (false);
	while (line[i] != '\n' || line[i] != '\0')
	{
		if (line[i] == '\n' && i != 0)
			break ;
		if (line[i] != c)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	check_no_lines_left(char *line, int fd, t_params *var)
{
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			free(line);
			close(fd);
			exit_on_error(var, MAP_ERROR);
		}
		line = get_new_line(line, fd);
	}
}

void	found_map_dimensions(char *path, t_params *var)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	handle_fd_error(var, fd, "Error - fail to open map file");
	line = get_next_line(fd);
	while (line != NULL && !is_map_line(line))
		line = get_new_line(line, fd);
	while (line != NULL && is_map_line(line))
	{
		i++;
		if ((int)ft_strlen(line) > j)
			j = ft_strlen(line);
		free_variable((void **)&line);
		line = get_next_line(fd);
	}
	check_no_lines_left(line, fd, var);
	var->map_height = i;
	var->map_width = j;
	close(fd);
}
