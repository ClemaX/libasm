/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_strcpy.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:42:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 18:01:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int	unit_ft_strcpy_basic(void)
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

int (*tests_ft_strcpy[])(void) = {&unit_ft_strcpy_basic, NULL};
