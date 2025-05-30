/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:21:43 by afloris           #+#    #+#             */
/*   Updated: 2025/05/04 21:38:07 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*l_occurence;

	l_occurence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			l_occurence = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)l_occurence);
}
