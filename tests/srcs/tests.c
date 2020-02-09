/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:38:50 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libasm.h>
#include <tests.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	test_ft_strlen(void)
{
	static const char	*str = "Thelengthistwentyone!";

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int	test_ft_strcpy(void)
{
	static const char	*src = "Copyright (c)";
	char				*dst;
	int					diff;

	dst = malloc(sizeof(*dst) * 14);
	ft_strcpy(dst, src);
	diff = diff_s(dst, src);
	free(dst);
	return (!diff);
}

int	test_ft_strcmp(void)
{
	char	*src;
	char	*dst;
	int		diff;
	int		err;

	src = rand_key(ft_rand(0, 10));
	dst = rand_key(ft_rand(0, 10));
	diff = 
		(err = (!src || !dst))
		? -1
		: diff_bool("sign", ft_strcmp(dst, src) < 0, strcmp(dst, src) < 0);
	free(src);
	free(dst);
	if (err)
		error();
	return (!diff);
}

int	test_ft_write(void)
{
	static const int	len = 4;
	static const char	*expected = "Wow!";
	char				got[len];
	int					diff;
	int					pipe_fd[2];

	pipe(pipe_fd);
	diff = diff_ssize(ft_write(pipe_fd[1], expected, len), write(pipe_fd[1], expected, len));
	diff += diff_ssize(ft_write(pipe_fd[1], expected, 0), write(pipe_fd[1], expected, 0));
	diff += diff_ssize(ft_write(pipe_fd[1], expected, -1), write(pipe_fd[1], expected, -1));
	close(pipe_fd[1]);
	diff_ssize(read(pipe_fd[0], got, len), len);
	close(pipe_fd[0]);
	diff += diff_s(got, expected);
	diff += diff_ssize(ft_write(-1, expected, len), write(-1, expected, len));
	return (!diff);
}

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

int	main(void)
{
	static const int	fw = -9;
	int					err;

	err = 0;
	err |= !run_test("ft_strlen", fw, &test_ft_strlen);
	err |= !run_test("ft_strcpy", fw, &test_ft_strcpy);
	err |= !run_test("ft_strcmp", fw, &test_ft_strcmp);
	err |= !run_test("ft_write", fw, &test_ft_write);
	err |= !run_test("ft_read", fw, &test_ft_read);
	return (err);
}