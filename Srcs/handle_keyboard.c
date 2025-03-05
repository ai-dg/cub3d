/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:19:47 by ls                #+#    #+#             */
/*   Updated: 2024/09/04 11:04:16 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

int	handle_key_press(int key, t_params *var)
{
	if (key == XK_w || key == XK_W || key == XK_Up)
		var->move_forward = 1;
	else if (key == XK_s || key == XK_S || key == XK_Down)
		var->move_backwards = 1;
	else if (key == XK_a || key == XK_A)
		var->move_left = 1;
	else if (key == XK_d || key == XK_D)
		var->move_right = 1;
	else if (key == XK_h || key == XK_H)
		var->cursor_hide = ft_toogle(var->cursor_hide);
	else if (key == XK_g || key == XK_G)
		var->gradient = ft_toogle(var->gradient);
	else if (key == XK_m || key == XK_M)
		var->show_map = ft_toogle(var->show_map);
	else if (key == XK_Right)
		var->rotate_right = 1;
	else if (key == XK_Left)
		var->rotate_left = 1;
	else if (key == XK_Escape || key == 17)
		var->close = 1;
	else if (key == XK_p || key == XK_P)
		print_datas(var);
	else if (key == XK_space)
		handle_space_key(var);
	return (0);
}

int	handle_close(t_params *var)
{
	var->close = 1;
	return (0);
}

int	handle_key_release(int key, t_params *var)
{
	if (key == XK_w || key == XK_W || key == XK_Up)
		var->move_forward = 0;
	else if (key == XK_s || key == XK_S || key == XK_Down)
		var->move_backwards = 0;
	else if (key == XK_a || key == XK_A)
		var->move_left = 0;
	else if (key == XK_d || key == XK_D)
		var->move_right = 0;
	else if (key == XK_Right)
		var->rotate_right = 0;
	else if (key == XK_Left)
		var->rotate_left = 0;
	return (0);
}
