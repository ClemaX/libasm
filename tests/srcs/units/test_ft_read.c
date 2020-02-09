/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_read.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:42:02 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:57:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int	test_ft_read(void)
{
	int		diff;
	char	c;
	int		pipe_fd[2];

	pipe(pipe_fd);
	write(pipe_fd[1], "ABCDEF", 6);
	close(pipe_fd[1]);
	diff = diff_ssize(ft_read(pipe_fd[0], &c, 1), read(pipe_fd[0], &c, 1));
	diff += diff_ssize(ft_read(pipe_fd[0], &c, 0), read(pipe_fd[0], &c, 0));
	diff += diff_ssize(ft_read(pipe_fd[0], &c, -1), read(pipe_fd[0], &c, -1));
	diff += diff_ssize(ft_read(-1, &c, 1), read(-1, &c, 1));
	close(pipe_fd[0]);
	return (!diff);
}
