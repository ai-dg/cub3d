/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:08:48 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	count_printable(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
			count++;
		i++;
	}
	return (count);
}

char	*get_path_from_line(t_params *var, char *line)
{
	char	*path;
	char	**splitted;

	splitted = ft_nsplit(line, ' ', 1);
	if (!splitted)
		exit_on_error(var, "fail on memory allocation\n");
	if (ft_count_args(splitted) < 2)
		return (free_array(&splitted), NULL);
	path = ft_strdup(splitted[1]);
	ft_unallocated_trim(path);
	return (free_array(&splitted), path);
}

void	set_gsv(char *line, t_params *var)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		var->gsv[NORTH - 1] = 1;
	if (ft_strncmp(line, "SO", 2) == 0)
		var->gsv[SOUTH - 1] = 1;
	if (ft_strncmp(line, "EA", 2) == 0)
		var->gsv[EAST - 1] = 1;
	if (ft_strncmp(line, "WE", 2) == 0)
		var->gsv[WEST - 1] = 1;
	if (ft_strncmp("F ", line, 2) == 0)
		var->gsv[FLOOR - 1] = 1;
	if (ft_strncmp("C ", line, 2) == 0)
		var->gsv[CEIL - 1] = 1;
}

int	check_line(char *line, t_params *var, int *comp)
{
	int			err;
	static int	completed = 0;

	err = 0;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		completed++;
	if (ft_strncmp(line, "NO", 2) == 0 && !var->graphics->north_wall_path)
		var->graphics->north_wall_path = get_path_from_line(var, line);
	if (ft_strncmp(line, "SO", 2) == 0 && !var->graphics->south_wall_path)
		var->graphics->south_wall_path = get_path_from_line(var, line);
	if (ft_strncmp(line, "EA", 2) == 0 && !var->graphics->east_wall_path)
		var->graphics->east_wall_path = get_path_from_line(var, line);
	if (ft_strncmp(line, "WE", 2) == 0 && !var->graphics->west_wall_path)
		var->graphics->west_wall_path = get_path_from_line(var, line);
	if (ft_strncmp(line, "CD", 2) == 0 && !var->graphics->door_path)
		var->graphics->door_path = get_path_from_line(var, line);
	if (ft_strncmp(line, "OD", 2) == 0 && !var->graphics->open_door_path)
		var->graphics->open_door_path = get_path_from_line(var, line);
	if (ft_strncmp("F ", line, 2) == 0 || ft_strncmp("C ", line, 2) == 0)
		err = set_rgb_from_line(line, var);
	set_gsv(line, var);
	*comp = completed;
	return (err);
}

void	add_sprite(t_params *var, int y_pos, int x, int type)
{
	var->sprites[var->sprites_nbr].type = type;
	var->sprites[var->sprites_nbr].x = x;
	var->sprites[var->sprites_nbr].y = y_pos;
	var->sprites[var->sprites_nbr].distance = -1;
	var->world_map[y_pos][x] = type;
	var->sprites_nbr++;
}
