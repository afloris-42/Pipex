/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_and_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:45:11 by afloris           #+#    #+#             */
/*   Updated: 2025/05/05 12:35:55 by afloris          ###   ########.fr       */
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
		perror("fork error");
	if (pid == 0)
		child_process(cmd, envp, fd, infile);
}

void	create_parent_process(char *cmd, char **envp, int *fd, int outfile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork error");
	if (pid == 0)
		parent_process(cmd, envp, fd, outfile);
}

void	child_process(char *cmd, char **envp, int *fd, int infile)
{
	close(fd[0]);
	if (infile < 0)
	{
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
	close(infile);
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
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(outfile);
	execute(cmd, envp);
}
