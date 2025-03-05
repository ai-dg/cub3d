/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_map_side_dist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:24:15 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	update_side_distances(t_params *var)
{
	if (var->calc.side_dist_x < var->calc.side_dist_y)
	{
		var->calc.side_dist_x += var->calc.delta_dist_x;
		var->player.map_x += var->calc.step_x;
		var->calc.step = 0;
	}
	else
	{
		var->calc.side_dist_y += var->calc.delta_dist_y;
		var->player.map_y += var->calc.step_y;
		var->calc.step = 1;
	}
}

static void	check_map_bounds(t_params *var)
{
	if (var->player.map_x < 0 || var->player.map_x >= var->map_width
		|| var->player.map_y < 0 || var->player.map_y >= var->map_height)
	{
		var->calc.collission = 1;
	}
}

static void	handle_map_elements(t_params *var)
{
	int	element;

	element = var->world_map[var->player.map_y][var->player.map_x];
	if (element == COIN)
		set_sprite_display(var, var->player.map_x, var->player.map_y, true);
	else if (element == WALL)
		var->calc.collission = 1;
	else if (element == CLOSED_DOOR)
		var->calc.collission = 2;
	else if (element == OPENED_DOOR)
	{
		var->calc.collission = 3;
		var->calc.door_found = 1;
	}
}

void	calculation_map_side_dist(t_params *var)
{
	while (var->calc.collission == 0)
	{
		update_side_distances(var);
		check_map_bounds(var);
		if (var->calc.collission)
			break ;
		handle_map_elements(var);
	}
}
