/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:41:56 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 17:19:54 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <tests.h>

int unit_ft_strlen_rand(void)
{
	static const int	len = 256;
	char				*str = rand_key(len);

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int unit_ft_strlen_zero(void)
{
	char	*str = "";

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int	unit_ft_strlen_basic(void)
{
	char	*str = "Thelengthistwentyone!";

	return (!diff_size(ft_strlen(str), strlen(str)));
}

int (*tests_ft_strlen[])(void) = {
	&unit_ft_strlen_basic,
	&unit_ft_strlen_zero,
	&unit_ft_strlen_rand,
	NULL
};
