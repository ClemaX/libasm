/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 18:37:36 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *rdi);
char*	ft_strcpy(const char *rdi, const char *rsi);
int		ft_strcmp(const char *rdi, const char *rsi);
ssize_t	ft_write(int edi, const void *rsi, int rdx);

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
	char	*src = rand_key(10);
	char	*dst = rand_key(10);
	int		diff = diff_i(ft_strcmp(dst, src), strcmp(dst, src));
	
	free(src);
	free(dst);
	return (!diff);
}

int	test_ft_write(void)
{
	static const int	len = 4;
	static const char	*str = "Wow!";
	int					diff = 0;

	diff += diff_ssize(ft_write(1, str, len), write(1, str, len));
	diff += diff_ssize(ft_write(1, str, -1), write(1, str, -1));
	diff += diff_ssize(ft_write(-1, str, len), write(-1, str, len));
	return (!diff);
}

int	main(void)
{
	static const int	fw = 9;
	int					err;

	err = 0;
	err |= !run_test("ft_strlen", fw, &test_ft_strlen);
	err |= !run_test("ft_strcpy", fw, &test_ft_strcpy);
	err |= !run_test("ft_strcmp", fw, &test_ft_strcmp);
	err |= !run_test("ft_write", fw, &test_ft_write);
	return (err);
}