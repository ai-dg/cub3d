/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_door.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:19:47 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 14:21:21 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	toogle_door(t_params *var, int x, int y)
{
	if (var->world_map[y][x] == 8)
		var->world_map[y][x] = 7;
	else if (var->world_map[y][x] == 7)
		set_value_at_pos(var, 8, x, y);
}

void	check_open_door(t_params *var)
{
	int	x;
	int	y;
	int	direction;

	direction = get_orientation(var);
	if (is_door_in_front(var, direction, &x, &y))
		toogle_door(var, x, y);
}

void	handle_space_key(t_params *var)
{
	check_open_door(var);
}
