/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:57:55 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 20:17:04 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	update_position(t_params *var, double x, double y)
{
	static int	old_val = 0;

	if (check_collision(var, x, var->player.pos.y))
		var->player.pos.x = x;
	if (check_collision(var, var->player.pos.x, y))
		var->player.pos.y = y;
	replace_value_in_map(var, old_val, 2);
	old_val = var->world_map[(int)var->player.pos.y][(int)var->player.pos.x];
	if (old_val == 9)
	{
		var->score += 100;
		old_val = 0;
	}
	if (var->player.pos.x < var->map_width
		&& var->player.pos.y < var->map_height)
		var->world_map[(int)var->player.pos.y][(int)var->player.pos.x] = 2;
}

void	longitudinal_move(t_params *var, double *x, double *y)
{
	if (var->move_forward == 1)
	{
		*x = var->player.pos.x + var->player.dir.x * MOVE_SPEED;
		*y = var->player.pos.y + var->player.dir.y * MOVE_SPEED;
	}
	if (var->move_backwards == 1)
	{
		*x = var->player.pos.x - var->player.dir.x * MOVE_SPEED;
		*y = var->player.pos.y - var->player.dir.y * MOVE_SPEED;
	}
}

void	lateral_move(t_params *var, double *x, double *y)
{
	if (var->move_left == 1)
	{
		*x = var->player.pos.x + var->player.dir.y * MOVE_SPEED;
		*y = var->player.pos.y - var->player.dir.x * MOVE_SPEED;
	}
	if (var->move_right == 1)
	{
		*x = var->player.pos.x - var->player.dir.y * MOVE_SPEED;
		*y = var->player.pos.y + var->player.dir.x * MOVE_SPEED;
	}
}

void	moves_player(t_params *var)
{
	double	new_x;
	double	new_y;

	new_x = var->player.pos.x;
	new_y = var->player.pos.y;
	longitudinal_move(var, &new_x, &new_y);
	lateral_move(var, &new_x, &new_y);
	get_mouse_pos(var);
	moves_rotate(var);
	update_position(var, new_x, new_y);
	reset_sprite_display(var);
	print_score(var);
}
