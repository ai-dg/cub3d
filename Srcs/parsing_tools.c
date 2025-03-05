/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:23:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/03 19:34:36 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube3d.h"

char	*get_new_line(char *line, int fd)
{
	free_variable((void **)&line);
	line = get_next_line(fd);
	ft_unallocated_trim(line);
	return (line);
}

bool	is_authorised_char(char c)
{
	char	*authorised;

	authorised = "12MNSEWO";
	if (find_index(c, authorised) > -1)
		return (true);
	return (false);
}
