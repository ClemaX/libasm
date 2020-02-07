/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:22:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *str);
int		diff_size(size_t got, size_t expected);
int		run_test(char *label, int fw, int (*test)());

int	test_ft_strlen(void)
{
	static const char	*str = "Thelengthistwentyone!";

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int	main(void)
{
	static const int	fw = 0;
	int					err;

	err = 0;
	err |= !run_test("ft_strlen", fw, &test_ft_strlen);
	return (err);
}