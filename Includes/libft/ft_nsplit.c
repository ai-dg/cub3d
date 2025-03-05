/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:35:41 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/05 08:07:52 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_nsplit(char const *s, char c, int step)
{
	char	**splitted;
	size_t	index;
	int		i;

	i = 0;
	index = 0;
	splitted = (char **)malloc((step + 2) * sizeof(char *));
	if (!splitted || !s)
		return (0);
	while (s[i] && step)
	{
		if (s[i] && s[i] == c)
			s++;
		if (s[i] && s[i] != c)
		{
			splitted[index++] = ft_substr(&s[i], 0, get_len(&s[i], c));
			i += get_len(&s[i], c);
			step--;
		}
	}
	if (s[i])
		splitted[index++] = ft_strdup(&s[i]);
	splitted[index] = NULL;
	return (splitted);
}
