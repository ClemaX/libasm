/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_strdup.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:41:58 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 18:01:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdlib.h>

int	test_ft_strdup(void)
{
	static const char	*src = "Copyright (c)";
	char				*dst;
	int					diff;

	if (!(dst = ft_strdup(src)))
		error();
	diff = diff_s(dst, src);
	free(dst);
	return (!diff);
}
