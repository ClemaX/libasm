/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 16:34:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 17:33:52 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>

int		run_test(char *label, int fw, int (*test)())
{
	int	ret;

	printf("%s %*s %s\n",
		BULLET, fw, label, (ret = (*test)()) ? PASS : FAIL);
	return (ret);
}
