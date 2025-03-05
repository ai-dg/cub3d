/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:55:55 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:17:34 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	resize_point(int *p, int max)
{
	if (*p < 0)
		*p = 0;
	if (*p > max)
		*p = max - 1;
}

void	draw_player(t_params *var)
{
	t_point	start;
	t_point	end;
	int		color;
	int		radius;

	color = 0x00FF0000;
	radius = 5;
	start.x = var->player.pos.p_x;
	start.y = var->player.pos.p_y;
	end.x = var->player.pos.p_x + (var->player.dir.x * 13);
	end.y = var->player.pos.p_y + (var->player.dir.y * 13);
	mlx_draw_line(&end, &start, var, color);
	draw_filled_circle(var, start, radius, color);
}

void	show_map(t_params *var)
{
	if (!var->bonus_map)
		return ;
	draw_map(var);
}
