/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:55:55 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 13:46:07 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	resize_over_limit(t_params *var, int *start, int *end)
{
	if (*start < 0)
		*start = 0;
	if (*end > var->map_height)
		*end = var->map_height;
}

void	set_map_x_limits(t_params *var, int *start, int *end)
{
	if (var->map_width < MAP_AROUND_PLAYER * 2)
	{
		*start = 0;
		*end = var->map_width;
	}
	else if ((int)var->player.pos.x + MAP_AROUND_PLAYER > var->map_width)
	{
		*end = var->map_width;
		*start = var->map_width - MAP_AROUND_PLAYER * 2;
	}
	else if ((int)var->player.pos.x - MAP_AROUND_PLAYER < 0)
	{
		*start = 0;
		*end = MAP_AROUND_PLAYER * 2;
	}
	else
	{
		if ((int)var->player.pos.x + MAP_AROUND_PLAYER <= var->map_width)
			*end = (int)var->player.pos.x + MAP_AROUND_PLAYER;
		if ((int)var->player.pos.x - MAP_AROUND_PLAYER >= 0)
			*start = (int)var->player.pos.x - MAP_AROUND_PLAYER;
	}
}

void	set_map_y_limits(t_params *var, int *start, int *end)
{
	if (var->map_width < MAP_AROUND_PLAYER * 2)
	{
		*start = 0;
		*end = var->map_height;
		printf("A\n");
	}
	else if ((int)var->player.pos.y - MAP_AROUND_PLAYER < 0)
	{
		*start = 0;
		*end = MAP_AROUND_PLAYER * 2;
	}
	else if ((int)var->player.pos.y + MAP_AROUND_PLAYER > var->map_height)
	{
		*start = var->map_height - MAP_AROUND_PLAYER * 2;
		*end = var->map_height;
	}
	else
	{
		if ((int)var->player.pos.y + MAP_AROUND_PLAYER <= var->map_height)
			*end = (int)var->player.pos.y + MAP_AROUND_PLAYER;
		if ((int)var->player.pos.y - MAP_AROUND_PLAYER >= 0)
			*start = (int)var->player.pos.y - MAP_AROUND_PLAYER;
	}
	resize_over_limit(var, start, end);
}

void	set_limits(t_params *var, t_map_data *map)
{
	map->offset.x = (var->screen_width) - (2 * MAP_AROUND_PLAYER * 16 + 10);
	map->offset.y = 10;
	set_map_x_limits(var, &map->start.x, &map->end.x);
	set_map_y_limits(var, &map->start.y, &map->end.y);
}
