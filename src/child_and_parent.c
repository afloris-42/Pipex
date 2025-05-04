/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_and_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:11 by afloris           #+#    #+#             */
/*   Updated: 2025/05/04 17:03:29 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

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

void	child_process(char *cmd, char **envp, int *fd, int infile)
{
	/*child is fd[1], so before anything else:*/
	close(fd[0]);
	/*check for mistakes*/
	if (infile < 0)
	{
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	/*if there are no mistake,
	start redirection*/
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	/*close the process*/
	close(fd[1]);
	close(infile);
	/*and execute comand and environment*/
	execute(cmd, envp);
}

void	parent_process(char *cmd, char **envp, int *fd, int outfile)
{
	close(fd[1]);

	if (outfile < 0)
	{
		close (fd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(outfile);
	execute(cmd, envp);
}