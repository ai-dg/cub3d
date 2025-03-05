/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_routine_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 23:13:19 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	set_sprite_display(t_params *var, int x, int y, bool value)
{
	int	i;

	i = 0;
	while (i < var->sprites_nbr)
	{
		if (var->sprites[i].x == x && var->sprites[i].y == y)
		{
			var->sprites[i].can_display = value;
			return ;
		}
		i++;
	}
}

void	reset_sprite_display(t_params *var)
{
	int	i;

	i = 0;
	while (i < var->sprites_nbr)
	{
		var->sprites[i].can_display = false;
		i++;
	}
}

void	swap_sprite(SPRITE_DATA *a, SPRITE_DATA *b)
{
	SPRITE_DATA	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	sprite_difference(SPRITE_DATA a, SPRITE_DATA b)
{
	if (a.distance > b.distance)
		return (1);
	if (a.distance < b.distance)
		return (-1);
	return (0);
}

int	set_frame(SPRITE *sprite)
{
	if (sprite->count % FRAME_SPEED == 0)
		sprite->frame_pos += 1;
	if (sprite->frame_pos >= sprite->frame)
		sprite->frame_pos = 0;
	if (sprite->count == LLONG_MAX)
		sprite->count = 0;
	sprite->count += 1;
	return (sprite->frame_pos);
}
