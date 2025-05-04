/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:14:57 by afloris           #+#    #+#             */
/*   Updated: 2025/05/04 21:38:05 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		dup[j] = s1[j];
		j++;
	}
	dup[i] = '\0';
	return (dup);
}
