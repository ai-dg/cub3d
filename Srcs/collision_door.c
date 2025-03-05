/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:12:15 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 12:03:53 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	get_offset(int direction, int *offset_x, int *offset_y)
{
	*offset_x = 0;
	*offset_y = 0;
	if (direction == 1)
		*offset_y = -1;
	else if (direction == 2)
		*offset_y = 1;
	else if (direction == 3)
		*offset_x = -1;
	else if (direction == 4)
		*offset_x = 1;
}

static bool	is_door(t_params *var, int offset_x, int offset_y)
{
	return (var->world_map[(int)var->player.pos.y
			+ offset_y][(int)var->player.pos.x + offset_x] == 8
			|| var->world_map[(int)var->player.pos.y
			+ offset_y][(int)var->player.pos.x + offset_x] == 7);
}

bool	is_door_in_front(t_params *var, int direction, int *x, int *y)
{
	int	offset_x;
	int	offset_y;

	get_offset(direction, &offset_x, &offset_y);
	if (is_in_map_range(var, var->player.pos.x + offset_x, var->player.pos.y
			+ offset_y))
	{
		if (is_door(var, offset_x, offset_y))
		{
			*x = (int)var->player.pos.x + offset_x;
			*y = (int)var->player.pos.y + offset_y;
			return (true);
		}
	}
	return (false);
}
