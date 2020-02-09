/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 16:34:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:36:24 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int		run_test(char *label, int fw, int (*test)())
{
	int	ret;

	printf("%s %*s %s\n",
		BULLET, fw, label, (ret = (*test)()) ? PASS : FAIL);
	return (ret);
}

void	error(void)
{
	perror(strerror(errno));
	exit(1);
}