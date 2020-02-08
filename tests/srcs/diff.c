/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   diff.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 17:30:53 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 18:23:59 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>
#include <string.h>

int		diff_s(const char *got, const char *expected)
{
	int	diff;

	if ((diff = strcmp(got, expected)))
		printf("%s: got: %s, expected: %s\n",
			RED"DIFF"RESET, got, expected);
	return (diff != 0);
}

int		diff_p(void *got, void *expected)
{
	if (got != expected)
	{
		printf("%s: got: %p, expected: %p\n",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}

int		diff_i(int got, int expected)
{
	if (got != expected)
	{
		printf("%s: got: %d, expected: %d\n",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}

int		diff_size(size_t got, size_t expected)
{
	if (got != expected)
	{
		printf("%s: got: %zu, expected: %zu\n",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}

int		diff_ssize(ssize_t got, ssize_t expected)
{
	if (got != expected)
	{
		printf("%s: got: %zd, expected: %zd\n",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}