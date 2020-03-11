/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/10 22:37:31 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libasm.h>
#include <tests.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	static const int	fw = -18;
	int					err;

	err = 0;
	err |= !run_test("ft_strlen", fw, &test_ft_strlen);
	err |= !run_test("ft_strcpy", fw, &test_ft_strcpy);
	err |= !run_test("ft_strcmp", fw, &test_ft_strcmp);
	err |= !run_test("ft_write", fw, &test_ft_write);
	err |= !run_test("ft_read", fw, &test_ft_read);
	err |= !run_test("ft_strdup", fw, &test_ft_strdup);
	err |= !run_test("ft_atoi_base", fw, &test_ft_atoi_base);
	err |= !run_test("ft_list_push_front", fw, &test_ft_list_push_front);
	return (err);
}
