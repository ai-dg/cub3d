/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:28:39 by ls                #+#    #+#             */
/*   Updated: 2024/09/30 15:34:37 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

bool	is_player_in_world_map(t_params *var)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < var->map_height)
	{
		while (j < var->map_width)
		{
			if (var->world_map[i][j] == 2)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count < 1)
		exit_on_error(var, "No player in the map");
	else if (count > 1)
		exit_on_error(var, "More than 1 player in the map");
	return (true);
}

bool	is_map_valid(t_params *var)
{
	if (var->map_height < 3 || var->map_width < 3)
		return (false);
	if (!is_player_in_world_map(var))
		return (false);
	return (true);
}

bool	flood_fill_internal(int **map, t_params *var, int x, int y)
{
	bool	top;
	bool	bottom;
	bool	left;
	bool	right;

	if (x < 0 || x >= var->map_height || y < 0 || y >= var->map_width)
	{
		var->x_check = x;
		var->y_check = y;
		return (true);
	}
	if (map[x][y] == 5)
	{
		var->x_check = x;
		var->y_check = y;
		return (true);
	}
	if (map[x][y] == 1 || map[x][y] == 6)
		return (false);
	map[x][y] = 6;
	top = flood_fill_internal(map, var, x - 1, y);
	bottom = flood_fill_internal(map, var, x + 1, y);
	left = flood_fill_internal(map, var, x, y - 1);
	right = flood_fill_internal(map, var, x, y + 1);
	return (top || bottom || left || right);
}

void	map_checks(int **map, int x, int y, int *zero)
{
	if (map[x + 1][y] == 0)
		*zero += 1;
	if (map[x - 1][y] == 0)
		*zero += 1;
	if (map[x][y + 1] == 0)
		*zero += 1;
	if (map[x][y - 1] == 0)
		*zero += 1;
	if (map[x + 1][y + 1] == 0)
		*zero += 1;
	if (map[x - 1][y - 1] == 0)
		*zero += 1;
	if (map[x + 1][y - 1] == 0)
		*zero += 1;
	if (map[x - 1][y + 1] == 0)
		*zero += 1;
}

void	flood_fill(int **map, t_params *var, int x, int y)
{
	int	zero;

	zero = 0;
	if (x < 0 || x >= var->map_height || y < 0
		|| y >= var->map_width || map[x][y] != 0)
		return ;
	if (x > 0 && x < var->map_height - 1 && y > 0 && y < var->map_width - 1)
	{
		map_checks(map, x, y, &zero);
		if (zero >= 2)
		{
			zero = 0;
			return ;
		}
	}
	map[x][y] = 5;
	flood_fill(map, var, x + 1, y);
	flood_fill(map, var, x - 1, y);
	flood_fill(map, var, x, y + 1);
	flood_fill(map, var, x, y - 1);
}
