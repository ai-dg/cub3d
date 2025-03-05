/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:30:53 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:12:53 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	get_mouse_pos(t_params *var)
{
	var->mouse.oldx = var->mouse.x_pos;
	mlx_mouse_get_pos(var->mlx, var->win, &var->mouse.x_pos, &var->mouse.y_pos);
}

int	mouse_hook(int mousecode, int x, int y, t_params *var)
{
	(void)x;
	(void)y;
	(void)var;
	if (mousecode == 5)
		ft_drop();
	if (mousecode == 4)
		ft_drop();
	return (0);
}
