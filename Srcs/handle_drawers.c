/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_drawers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:55:04 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/05 19:50:49 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	set_drawer(t_draw *drawer, t_point o, t_point dest)
{
	int	delta_x;
	int	delta_y;

	delta_x = dest.x - o.x;
	delta_y = dest.y - o.y;
	drawer->x = o.x;
	drawer->y = o.y;
	drawer->delta_x = abs(delta_x);
	drawer->delta_y = abs(delta_y);
	drawer->add_x = get_sign(delta_x);
	drawer->add_y = get_sign(delta_y);
}
