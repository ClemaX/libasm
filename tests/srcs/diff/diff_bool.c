/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   diff_bool.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:10:29 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:32:39 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>

int		diff_bool(const char *label, char got, char expected)
{
	if (got != expected)
	{
		printf("%s: Wrong %s",
			RED"DIFF"RESET, label);
		return (1);
	}
	return (0);
}
