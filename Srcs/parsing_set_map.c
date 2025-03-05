/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_set_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:23:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:05:53 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static bool	allocate_map_row(t_params *var, int y_pos)
{
	var->world_map[y_pos] = malloc(sizeof(int) * var->map_width);
	ft_bzero(var->world_map[y_pos], sizeof(int) * var->map_width);
	return (var->world_map[y_pos] != NULL);
}

static bool	is_allowed_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'E'
		|| c == 'S' || c == 'O' || c == 'M' || c == 'D' || c == 'W'
		|| c == '\n')
		return (true);
	return (false);
}

static int	set_map_value(t_params *var, char tile, int y_pos, int x)
{
	if (!is_allowed_char(tile))
		return (-1);
	if (tile == '1')
		var->world_map[y_pos][x] = WALL;
	else if (tile == 'D')
		var->world_map[y_pos][x] = CLOSED_DOOR;
	else if (tile == 'N')
		init_position(var, y_pos, x, NORTH);
	else if (tile == 'S')
		init_position(var, y_pos, x, SOUTH);
	else if (tile == 'E')
		init_position(var, y_pos, x, EAST);
	else if (tile == 'W')
		init_position(var, y_pos, x, WEST);
	else if (tile == 'M')
		add_sprite(var, y_pos, x, COIN);
	else if (tile == ' ' || tile == '\n')
	{
		var->world_map[y_pos][x] = EXTERN_MAP;
	}
	else
		var->world_map[y_pos][x] = EMPTY;
	return (0);
}

int	set_map(char *line, int y_pos, t_params *var)
{
	int		x;
	int		error;
	bool	over;

	over = false;
	error = 0;
	x = -1;
	if (!allocate_map_row(var, y_pos))
		return (free_variable((void **)&line), -1);
	while (++x < var->map_width)
	{
		if (x > (int)ft_strlen(line) - 1)
			over = true;
		if (!over)
			error = set_map_value(var, line[x], y_pos, x);
		else
			error = set_map_value(var, ' ', y_pos, x);
		if (error < 0)
			var->error = error;
	}
	while (++x < var->map_width)
		var->world_map[y_pos][x] = EXTERN_MAP;
	return (0);
}
