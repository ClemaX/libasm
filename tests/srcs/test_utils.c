/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 16:34:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:23:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#define RESET  "\033[0m"
#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define CYAN   "\033[0;36m"
#define TITLE  "\033[1;34m"
#define PASS   GREEN"✔"RESET
#define FAIL   RED"✗"RESET
#define BULLET CYAN"▶"RESET

#include <stdlib.h>
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

int		run_test(char *label, int fw, int (*test)())
{
	int	ret;

	printf("%s %*s %s\n",
		BULLET, fw, label, (ret = (*test)()) ? PASS : FAIL);
	return (ret);
}
