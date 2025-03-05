/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:54:43 by ls                #+#    #+#             */
/*   Updated: 2024/08/17 14:01:40 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

void	debug_z(double *buffer, t_params *var)
{
	int	i;

	i = 0;
	while (i < var->screen_width)
	{
		if (buffer[i] != DBL_MAX)
			printf("%f - ", buffer[i]);
		i++;
	}
}

void	free_zbuffer(t_params *var)
{
	free(var->zbuffer);
	printf("free zbuffer\n");
}

void	free_zdoor(t_params *var)
{
	free(var->zdoor);
}

double	*init_zbuffer(t_params *var, double *buffer)
{
	static int	count;

	count = 0;
	buffer = (double *)malloc(var->screen_width * var->screen_height
			* sizeof(double));
	if (buffer == NULL)
	{
		ft_fprintf(stderr, "Failed to allocate memory for Z-buffer\n");
		exit_on_error(var, "Fail on memory allocation");
	}
	if (count == 0)
		var->free_stage++;
	count++;
	reset_zbuffer(var, buffer);
	return (buffer);
}

void	reset_zbuffer(t_params *var, double *zbuffer)
{
	int	i;

	i = 0;
	while (i < var->screen_width * var->screen_height)
	{
		zbuffer[i] = DBL_MAX;
		i++;
	}
}
