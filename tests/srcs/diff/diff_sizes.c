/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   diff_sizes.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:10:31 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:32:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <string.h>
#include <stdio.h>

int		diff_size(size_t got, size_t expected)
{
	if (got != expected)
	{
		printf("%s: got: %zu, expected: %zu",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}

int		diff_ssize(ssize_t got, ssize_t expected)
{
	if (got != expected)
	{
		printf("%s: got: %zd, expected: %zd",
			RED"DIFF"RESET, got, expected);
		return (1);
	}
	return (0);
}
