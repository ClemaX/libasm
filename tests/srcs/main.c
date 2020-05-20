/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 17:47:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/11 16:26:35 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libasm.h>
#include <tests.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	run_basic(void)
{
	int err;

	err = 0;
	err |= !run_tests("ft_strlen", tests_ft_strlen);
	err |= !run_tests("ft_strcpy", tests_ft_strcpy);
	err |= !run_tests("ft_strcmp", tests_ft_strcmp);
	err |= !run_tests("ft_write", tests_ft_write);
	err |= !run_tests("ft_read", tests_ft_read);
	err |= !run_tests("ft_strdup", tests_ft_strdup);
	return (err);
}

static int run_bonus(void)
{
	int err;

	err = 0;
	err |= !run_tests("ft_atoi_base", tests_ft_atoi_base);
	err |= !run_tests("ft_list_push_front", tests_ft_list_push_front);
	err |= !run_tests("ft_list_size", tests_ft_list_size);
	err |= !run_tests("ft_list_remove_if", tests_ft_list_remove_if);
	return (err);
}

int			main(void)
{
	int	err;

	err = 0;
	err |= run_basic();
	err |= run_bonus();
	return (err);
}
