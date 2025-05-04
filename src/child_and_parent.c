/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_and_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:11 by afloris           #+#    #+#             */
/*   Updated: 2025/05/04 15:55:09 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/libft.h"
#include "../include/printf.h"

void	create_child_process(char *cmd, char **envp, int *fd, int infile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		write(1, "fork error", 10);
	if (pid == 0)
		child_process(cmd, envp, fd, infile);
}

void	create_parent_process(char *cmd, char **envp, int *fd, int outfile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		write(1, "fork error", 10);
	if (pid == 0)
		parent_process(cmd, envp, fd, outfile);
}