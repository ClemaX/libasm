/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_write.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:42:10 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 18:19:09 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int unit_ft_write_errno(void)
{
	int		diff;
	char	c;
	int		expected_ret;
	int		expected_errno;
	int		got_ret;

	c = '\0';
	expected_ret = write(-1, &c, 1);
	expected_errno = errno;
	errno = 0;
	got_ret = ft_write(-1, &c, 1);
	diff = diff_i(errno, expected_errno);
	diff += diff_i(got_ret, expected_ret);
	return(!diff);
}

int	unit_ft_write_pipe(void)
{
	static const int	len = 4;
	static const char	*expected = "Wow!";
	char				got[len + 1];
	int					diff;
	int					pipe_fd[2];

	pipe(pipe_fd);
	diff = diff_ssize(ft_write(pipe_fd[1], expected, len), write(pipe_fd[1], expected, len));
	diff += diff_ssize(ft_write(pipe_fd[1], expected, 0), write(pipe_fd[1], expected, 0));
	diff += diff_ssize(ft_write(pipe_fd[1], expected, -1), write(pipe_fd[1], expected, -1));
	close(pipe_fd[1]);
	diff_ssize(read(pipe_fd[0], got, len), len);
	close(pipe_fd[0]);
	got[len] = '\0';
	diff += diff_s(got, expected);
	diff += diff_ssize(ft_write(-1, expected, len), write(-1, expected, len));
	return (!diff);
}

int (*tests_ft_write[])(void) = {&unit_ft_write_pipe, &unit_ft_write_errno, NULL};
