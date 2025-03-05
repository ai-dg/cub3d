/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/30 15:00:37 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	check_unclosed_areas(t_params *var)
{
	int	**map_copy;
	int	i;
	int	j;

	i = -1;
	j = -1;
	map_copy = copy_map(var->world_map, var->map_height, var->map_width);
	if (!map_copy)
		exit_on_error(var, "Fail on map init");
	while (++i < var->map_height)
	{
		while (++j < var->map_width)
		{
			if (map_copy[i][j] == 0 && flood_fill_internal(map_copy, var, i, j))
			{
				free_map(map_copy, var->map_height);
				msg_and_exit(var, "The map has an unclosed area",
					var->y_check, var->x_check);
			}
		}
		j = -1;
	}
	printf("No unclosed areas detected.\n");
	free_map(map_copy, var->map_height);
}

static void	check_surrounded_walls(t_params *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map_height)
	{
		if (var->world_map[i][0] == 0)
			flood_fill(var->world_map, var, i, 0);
		if (var->world_map[i][var->map_width - 1] == 0)
			flood_fill(var->world_map, var, i, var->map_width - 1);
		i++;
	}
	while (j < var->map_width)
	{
		if (var->world_map[0][j] == 0)
			flood_fill(var->world_map, var, 0, j);
		if (var->world_map[var->map_height - 1][j] == 0)
			flood_fill(var->world_map, var, var->map_height - 1, j);
		j++;
	}
	printf("check_surrounded_walls...\n");
}

void	check_if_player_twice(t_params *var)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < var->map_height)
	{
		j = 0;
		while (j < var->map_width)
		{
			if (var->world_map[i][j] == 2)
			{
				count++;
				if (count > 1)
					msg_and_exit(var, "The map must contain just one player",
						-1, -1);
			}
			j++;
		}
		i++;
	}
}

void	change_map(t_params *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map_height)
	{
		j = 0;
		while (j < var->map_width)
		{
			if (var->world_map[i][j] == COIN
				|| var->world_map[i][j] == CLOSED_DOOR)
				var->world_map[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	check_map(t_params *var)
{
	if (var->bonus_map == false)
		change_map(var);
	check_surrounded_walls(var);
	check_unclosed_areas(var);
	replace_map_data(var);
	check_valid_char(var);
	check_if_player_twice(var);
	printf("init world map ok...\n");
}
