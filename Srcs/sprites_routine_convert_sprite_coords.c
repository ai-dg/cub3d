/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_routine_convert_sprite_coords.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/15 16:05:28 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

static void	calculate_transform(SPRITE_DATA *sprite, t_params *var,
		t_sprite_transform *transform)
{
	sprite->transform_x = transform->inv_det * (var->player.dir.y
			* transform->sprite_x - var->player.dir.x * transform->sprite_y);
	sprite->transform_y = transform->inv_det * (-var->player.plan.y
			* transform->sprite_x + var->player.plan.x * transform->sprite_y);
}

static void	calculate_screen_position(SPRITE_DATA *sprite, t_params *var)
{
	sprite->screen_x = (int)((var->screen_width / 2) * (1 + sprite->transform_x
				/ sprite->transform_y));
}

static void	calculate_sprite_dimensions(SPRITE_DATA *sprite, t_params *var)
{
	sprite->height = abs((int)(var->screen_width / sprite->transform_y) / 2);
	sprite->width = abs((int)(var->screen_height / sprite->transform_y) / 2);
}

static void	calculate_draw_limits(SPRITE_DATA *sprite, t_params *var)
{
	sprite->draw_start_y = -sprite->height / 2 + var->screen_height / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + var->screen_height / 2;
	if (sprite->draw_end_y >= var->screen_height)
		sprite->draw_end_y = var->screen_height - 1;
	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= var->screen_width)
		sprite->draw_end_x = var->screen_width - 1;
}

void	convert_sprite_coords(t_params *var, SPRITE_DATA *sprite)
{
	t_sprite_transform	transform;

	transform.sprite_x = sprite->x + 0.5 - var->player.pos.x;
	transform.sprite_y = sprite->y + 0.5 - var->player.pos.y;
	transform.inv_det = 1.0 / (var->player.plan.x * var->player.dir.y
			- var->player.dir.x * var->player.plan.y);
	calculate_transform(sprite, var, &transform);
	calculate_screen_position(sprite, var);
	calculate_sprite_dimensions(sprite, var);
	calculate_draw_limits(sprite, var);
}
