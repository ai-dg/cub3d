/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_routine_render_sprites.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:02:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/28 11:33:59 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	display_sprites_pixels(t_render_sprite *render, t_params *var,
		t_image *current_frame)
{
	int	index;

	index = render->y * render->var->image.line_length / 4 + render->x;
	render->calc.color = current_frame->addr[render->calc.index];
	if (((render->calc.color & 0x00FFFFFF) != 0
			&& (render->calc.color & 0xFF000000) == 0))
		render->var->image.addr[index] = render->calc.color;
	if ((render->calc.color & 0x00FFFFFF) != 0
		&& (render->calc.color & 0xFF000000) == 0
		&& var->zdoor[render->x] > render->var->sprites[render->i].transform_y)
		render->var->image.addr[index] = render->calc.color;
	else if ((render->calc.color & 0x00FFFFFF) != 0
		&& (render->calc.color & 0xFF000000) == 0
		&& var->zdoor[render->x] < render->var->sprites[render->i].transform_y
		&& var->doors.addr[index] != 0)
		render->var->image.addr[index] = var->doors.addr[index];
}

void	render_single_sprite_y(t_render_sprite *render, t_params *var)
{
	t_image	*current_frame;

	while (render->y < render->var->sprites[render->i].draw_end_y)
	{
		render->calc.texture_y_offset = (render->y) * 256
			- render->var->screen_height * 128
			+ render->var->sprites[render->i].height * 128;
		render->calc.texture_y = ((render->calc.texture_y_offset
					* render->spr->frames[render->spr->frame_pos].height)
				/ render->var->sprites[render->i].height) / 256;
		render->calc.index = render->calc.texture_y
			* render->spr->frames[render->spr->frame_pos].line_length / 4
			+ render->calc.texture_x;
		current_frame = &render->spr->frames[render->spr->frame_pos];
		if (render->calc.index < 0 || render->calc.index >= current_frame->width
			* render->spr->frames[render->spr->frame_pos].height)
			break ;
		display_sprites_pixels(render, var, current_frame);
		render->y++;
	}
}

void	render_single_sprite_x(t_render_sprite *render, t_params *var)
{
	while (render->x < render->var->sprites[render->i].draw_end_x)
	{
		if (render->x >= 0 && render->x < render->var->screen_width
			&& render->var->sprites[render->i].transform_y
			< render->var->zbuffer[render->x]
			&& render->var->sprites[render->i].can_display)
		{
			render->calc.texture_x = (int)(256 * (render->x
						- (-render->var->sprites[render->i].width / 2
							+ render->var->sprites[render->i].screen_x))
					* render->spr->frames[render->spr->frame_pos].width
					/ render->var->sprites[render->i].width) / 256;
			render->y = render->var->sprites[render->i].draw_start_y;
			render_single_sprite_y(render, var);
		}
		render->x++;
	}
}

void	render_sprites(t_params *var)
{
	t_render_sprite	render;
	t_sprite		*spr;
	int				i;

	i = 0;
	spr = var->coins;
	set_frame(spr);
	while (i < var->sprites_nbr)
	{
		convert_sprite_coords(var, &var->sprites[i]);
		render.x = var->sprites[i].draw_start_x;
		render.var = var;
		render.i = i;
		render.y = var->sprites[i].draw_start_y;
		render.spr = spr;
		render_single_sprite_x(&render, var);
		i++;
	}
}
