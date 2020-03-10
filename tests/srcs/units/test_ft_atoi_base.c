/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_atoi_base.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/03 20:50:28 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/10 22:37:54 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>
#include <stdio.h>
#include <limits.h>

int	test_ft_atoi_base(void)
{
	static const int	len = 32;
	static const char	*base = "0123456789ABCDEF";
	char				src[len];
	int					dest;
	int					rand;

	rand = ft_rand(0, 0xffffffff);
	snprintf(src, len, "-+ -\t \t%X", rand);
	dest = ft_atoi_base(src, base);
	return (!diff_i(dest, rand));
}
