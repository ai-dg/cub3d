/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:13:56 by ls                #+#    #+#             */
/*   Updated: 2024/09/30 11:47:37 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	destroy_map_tiles(t_params *var)
{
	if (var->map_tiles)
		free_variable((void **)&var->map_tiles);
}

void	init_map_tiles(t_params *var)
{
	int	i;

	i = 0;
	var->map_tiles = malloc(sizeof(SPRITE *) * MAP_TILES_LENGTH);
	if (!var->map_tiles)
		exit_on_error(var, "Fail on memory allocation");
	var->free_stage++;
	ft_bzero(var->map_tiles, sizeof(SPRITE *) * MAP_TILES_LENGTH);
	while (i < 5)
	{
		var->map_tiles[i] = NULL;
		i++;
	}
}

int	init_map(t_params *var)
{
	if (var->map_height == 0 || var->map_width == 0)
		exit_on_error(var, "The map is empty");
	var->world_map = malloc((var->map_height + 1) * sizeof(char *));
	if (!var->world_map)
		return (-1);
	var->free_stage++;
	ft_ints_array_to_null(var->world_map, var->map_height + 1);
	return (0);
}

/**
 * @brief Initialise les valeurs de direction et de plan
 * en fonction de l'orientation initiale du joueur
 *
 */
void	init_calc(t_params *var)
{
	if (var->orientation == NORTH)
	{
		var->player.dir.y = -1;
		var->player.plan.x = PLANE;
	}
	if (var->orientation == SOUTH)
	{
		var->player.dir.y = 1;
		var->player.plan.x = -PLANE;
	}
	if (var->orientation == EAST)
	{
		var->player.dir.x = 1;
		var->player.plan.y = PLANE;
	}
	if (var->orientation == WEST)
	{
		var->player.dir.x = -1;
		var->player.plan.y = -PLANE;
	}
}

void	init_position(t_params *var, int y, int x, int orientation)
{
	var->world_map[y][x] = PLAYER;
	var->orientation = orientation;
	var->player.pos.x = x + 0.5;
	var->player.pos.y = y + 0.5;
}
