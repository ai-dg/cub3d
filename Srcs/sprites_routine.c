/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:58:24 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 09:25:53 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	set_sprites_distance(t_params *var)
{
	double	player_x;
	double	player_y;
	double	dist_x;
	double	dist_y;
	int		i;

	i = 0;
	player_x = var->player.pos.x;
	player_y = var->player.pos.y;
	while (i < var->sprites_nbr)
	{
		dist_x = var->sprites[i].x - player_x;
		dist_y = var->sprites[i].y - player_y;
		if (player_x > var->sprites[i].x)
			dist_x = player_x - var->sprites[i].x;
		if (player_y > var->sprites[i].y)
			dist_y = player_y - var->sprites[i].y;
		var->sprites[i].distance = (dist_x * dist_x) + (dist_y * dist_y);
		i++;
	}
	sort_sprites_by_distance(var);
}

void	sort_sprites_by_distance(t_params *var)
{
	int	i;

	(void)var;
	i = -1;
	while (var->sprites[++i].x >= 0)
	{
		if (sprite_difference(var->sprites[i], var->sprites[i + 1]) == -1)
		{
			swap_sprite(&var->sprites[i], &var->sprites[i + 1]);
			i = -1;
		}
	}
}

void	sprite_routine(t_params *var)
{
	set_sprites_distance(var);
	sort_sprites_by_distance(var);
	render_sprites(var);
	reset_zbuffer(var, var->zbuffer);
	reset_zbuffer(var, var->zdoor);
}
