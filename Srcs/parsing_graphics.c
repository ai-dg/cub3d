/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:23:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:14:39 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	init_graphics(t_graphics *graphics)
{
	graphics->east_wall_path = NULL;
	graphics->north_wall_path = NULL;
	graphics->south_wall_path = NULL;
	graphics->west_wall_path = NULL;
	graphics->door_path = NULL;
	graphics->open_door_path = NULL;
	return (0);
}

void	check_graphics(t_params *var)
{
	int	err;

	err = 0;
	if (!var->graphics->north_wall_path)
		err++;
	if (!var->graphics->south_wall_path)
		err++;
	if (!var->graphics->east_wall_path)
		err++;
	if (!var->graphics->west_wall_path)
		err++;
	if (err)
		exit_on_error(var, "error\nfail parsing texture paths");
}

void	check_gsv(int completed, t_params *var, int fd)
{
	int	i;

	i = 0;
	if (completed < 6)
	{
		close(fd);
		exit_on_error(var, "missing data in .cub file");
	}
	if (completed > 6)
	{
		close(fd);
		exit_on_error(var, "duplicate data in .cub file");
	}
	if (completed == 6)
	{
		while (i < completed)
		{
			if (var->gsv[i] != 1)
			{
				close(fd);
				exit_on_error(var, "missing data in .cub file");
			}
			i++;
		}
	}
}

void	process_graphics_parsing(t_params *var, char *line, int fd)
{
	int	completed;

	completed = 0;
	while (line)
	{
		init_bonus_part(var, line);
		if (check_line(line, var, &completed) == -2)
		{
			free(line);
			close(fd);
			var->free_stage++;
			exit_on_error(var, "Error - fail parsing colors");
		}
		if (completed < 6 && allowed_for_map(line))
		{
			free(line);
			close(fd);
			var->free_stage++;
			exit_on_error(var, "Error - map is not at the end");
		}
		line = get_new_line(line, fd);
	}
	var->free_stage++;
	check_gsv(completed, var, fd);
}

int	parsing_graphics(char *file, t_params *var)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	handle_fd_error(var, fd, "Error - fail to open map file");
	var->graphics = malloc(sizeof(t_graphics));
	if (!var->graphics)
		return (close(fd), exit_on_error(var,
				"Error - fail on memory allocation"), -1);
	ft_bzero(var->graphics, sizeof(t_graphics));
	var->free_stage++;
	init_graphics(var->graphics);
	line = get_next_line(fd);
	ft_unallocated_trim(line);
	process_graphics_parsing(var, line, fd);
	set_color_from_rbg(var->graphics);
	var->free_stage++;
	close(fd);
	check_graphics(var);
	return (ft_printf("init graphic textures ok...\n"), 0);
}
