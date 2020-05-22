/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:47:17 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 19:47:21 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <tests.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	run_basic(int iterations)
{
	int	err;

	err = 0;
	err |= !run_tests("ft_strlen", tests_ft_strlen, iterations);
	err |= !run_tests("ft_strcpy", tests_ft_strcpy, iterations);
	err |= !run_tests("ft_strcmp", tests_ft_strcmp, iterations);
	err |= !run_tests("ft_write", tests_ft_write, iterations);
	err |= !run_tests("ft_read", tests_ft_read, iterations);
	err |= !run_tests("ft_strdup", tests_ft_strdup, iterations);
	return (err);
}

static int run_bonus(int iterations)
{
	int	err;

	err = 0;
	err |= !run_tests("ft_atoi_base", tests_ft_atoi_base, iterations);
	err |= !run_tests("ft_list_push_front", tests_ft_list_push_front, iterations);
	err |= !run_tests("ft_list_size", tests_ft_list_size, iterations);
	err |= !run_tests("ft_list_remove_if", tests_ft_list_remove_if, iterations);
	return (err);
}

int			main(void)
{
	int	err;

	err = 0;
	err |= run_basic(3);
	err |= run_bonus(3);
	return (err);
}
