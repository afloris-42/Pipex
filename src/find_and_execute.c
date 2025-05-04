/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:55:36 by babyf             #+#    #+#             */
/*   Updated: 2025/05/04 15:44:20 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/libft.h"
#include "../include/printf.h"

/*envp is connection to environment
with this function i will get the path to find the command*/
char	get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5)
		i++;
	}
	return (NULL);
}

//check if the command exists
char	*check_command(char **paths, char *cmd)
{
	
}

char	*find_path(char *cmd, char **envp)
{
	
}

void	execute(char *cmd, char **envp)