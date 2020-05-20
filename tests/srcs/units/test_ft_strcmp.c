/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_strcmp.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:42:00 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 18:01:40 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int	unit_ft_strcmp_rand(void)
{
	char	*src;
	char	*dst;
	int		diff;
	int		err;

	src = rand_key(ft_rand(0, 10));
	dst = rand_key(ft_rand(0, 10));
	diff = 
		(err = (!src || !dst))
		? -1
		: diff_bool("sign", ft_strcmp(dst, src) < 0, strcmp(dst, src) < 0);
	free(src);
	free(dst);
	if (err)
		perror("Error");
	return (!diff);
}

int (*tests_ft_strcmp[])(void) = {&unit_ft_strcmp_rand, NULL};
