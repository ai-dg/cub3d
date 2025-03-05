/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:23:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:34:31 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static char	*skip_non_map_lines(int fd, char *line)
{
	while (!allowed_for_map(line))
	{
		if (allowed_for_map(line))
			break ;
		free_variable((void **)&line);
		line = get_next_line(fd);
	}
	return (line);
}

static void	process_map_lines(int fd, char *line, t_params *var, int *i)
{
	while (line)
	{
		if (*i == var->map_height)
			break ;
		if (set_map(line, *i, var) < 0)
		{
			close(fd);
			free_variable((void **)&line);
			free_on_map_error(var, var->free_stage, MAP_LENGTH_ERROR);
		}
		free_variable((void **)&line);
		line = get_next_line(fd);
		(*i)++;
	}
	if (line)
		free(line);
	if (var->error < 0)
	{
		close(fd);
		free_variable((void **)&line);
		var->free_stage++;
		free_on_map_error(var, var->free_stage, "Invalid character in map");
	}
}

void	check_valid_filename(char *file, t_params *var)
{
	if (ft_strncmp_backward(file, ".cub", 4) != 0)
		exit_on_error(var, "filename extension must be .cub");
}

void	parsing_map(char *file, t_params *var)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	check_valid_filename(file, var);
	fd = open(file, O_RDONLY);
	handle_fd_error(var, fd, "Error - fail to open map file");
	line = get_next_line(fd);
	line = skip_non_map_lines(fd, line);
	process_map_lines(fd, line, var, &i);
	var->free_stage++;
	close(fd);
	if (!is_map_valid(var))
		exit_on_error(var, "Invalid map");
}
