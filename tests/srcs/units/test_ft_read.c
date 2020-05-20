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

int unit_ft_read_errno(void)
{
	int		diff;
	char	c;
	int		expected_ret;
	int		expected_errno;
	int		got_ret;

	expected_ret = read(-1, &c, 1);
	expected_errno = errno;
	errno = 0;
	got_ret = ft_read(-1, &c, 1);
	diff = diff_i(errno, expected_errno);
	diff += diff_i(got_ret, expected_ret);
	return(!diff);
}

int	unit_ft_read_pipe(void)
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
	close(pipe_fd[0]);
	return (!diff);
}

int (*tests_ft_read[])(void) = {&unit_ft_read_pipe, &unit_ft_read_errno, NULL};
