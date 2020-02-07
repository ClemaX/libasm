/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 13:08:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *rdi);
char*	ft_strcpy(const char *rdi, const char *rsi);

int	test_ft_strlen(void)
{
	static const char	*str = "Thelengthistwentyone!";

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int	test_ft_strcpy(void)
{
	static const char	*src = "Copyright (c)";
	char				*dest;
	int					diff;

	dest = malloc(sizeof(*dest) * 14);
	ft_strcpy(dest, src);
	diff = diff_s(dest, src);
	free(dest);
	return (!diff);
}

int	main(void)
{
	static const int	fw = 0;
	int					err;

	err = 0;
	err |= !run_test("ft_strlen", fw, &test_ft_strlen);
	err |= !run_test("ft_strcpy", fw, &test_ft_strcpy);
	return (err);
}