/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:55:25 by babyf             #+#    #+#             */
/*   Updated: 2025/05/04 16:53:00 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_strjoin_free(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	free (s1);
	return (res);
}

void	initialize_files(char *in_path, char *out_path, int *infile, int *outfile)
{
	*infile = open(in_path, O_RDONLY);
	if (*infile < 0)
		perror("infile error");
	*outfile = open (out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(*outfile < 0)
		perror("outfile error");
}

//envp is an array of pointers to environment variables
int main (int argc, char **argv, char **envp)
{
	//variable declarations
	int	fd[2];
	int	infile;
	int outfile;
	//check argument count
	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (1);
	}
	initialize_files(argv[1], argv[4], &infile, &outfile);
	if (pipe(fd) == -1)
		perror("pipe error");
	create_child_process(argv[2], envp, fd, infile);
	create_parent_process(argv[3], envp, fd, outfile);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	return (0);
}