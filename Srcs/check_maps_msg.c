/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/12 10:16:30 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	msg_and_exit(t_params *var, char *msg, int i, int j)
{
	write(2, GLOBAL_ERR_MSG, ft_strlen(GLOBAL_ERR_MSG));
	if (i == -1 || j == -1)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(" at x = ", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" y = ", 2);
		ft_putnbr_fd(j, 2);
		ft_putstr_fd("\n", 2);
	}
	exit_on_error(var, NULL);
}
