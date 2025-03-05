/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:54:06 by calbor-p          #+#    #+#             */
/*   Updated: 2024/07/31 07:37:59 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	draw_v_lines(t_point o, t_point dest, t_params *var)
{
	t_draw	p;

	set_drawer(&p, o, dest);
	while (p.y != dest.y + p.add_y)
	{
		set_pix_color(&var->image, p.x, p.y, dest.color);
		p.y += p.add_y;
	}
}

void	draw_h_lines(t_point o, t_point dest, t_params *var)
{
	t_draw	p;

	set_drawer(&p, o, dest);
	while (p.x != dest.x + p.add_x)
	{
		set_pix_color(&var->image, p.x, p.y, dest.color);
		p.x += p.add_x;
	}
}

void	draw_more_h_lines(t_point o, t_point dest, t_params *var)
{
	t_draw	p;

	set_drawer(&p, o, dest);
	p.slope = 2 * p.delta_y;
	p.error = -p.delta_x;
	p.add_error = -2 * p.delta_x;
	while (p.x != dest.x + p.add_x)
	{
		set_pix_color(&var->image, p.x, p.y, dest.color);
		p.error += p.slope;
		if (p.error >= 0)
		{
			p.y += p.add_y;
			p.error += p.add_error;
		}
		p.x += p.add_x;
	}
}

void	draw_more_v_lines(t_point o, t_point dest, t_params *var)
{
	t_draw	p;

	set_drawer(&p, o, dest);
	p.slope = 2 * p.delta_x;
	p.error = -p.delta_y;
	p.add_error = -2 * p.delta_y;
	while (p.y != dest.y + p.add_y)
	{
		set_pix_color(&var->image, p.x, p.y, dest.color);
		p.error += p.slope;
		if (p.error >= 0)
		{
			p.x += p.add_x;
			p.error += p.add_error;
		}
		p.y += p.add_y;
	}
}

void	mlx_draw_line(t_point *o, t_point *dest, t_params *var, int color)
{
	t_draw	drawer;

	if (!o || !dest)
		return ;
	if (color > -1)
		dest->color = color;
	set_drawer(&drawer, *o, *dest);
	if (o->y == dest->y)
		draw_h_lines(*o, *dest, var);
	else if (o->x == dest->x)
		draw_v_lines(*o, *dest, var);
	else if (drawer.delta_x >= drawer.delta_y)
		draw_more_h_lines(*o, *dest, var);
	else
		draw_more_v_lines(*o, *dest, var);
}
