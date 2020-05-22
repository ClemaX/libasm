/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:42:21 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 20:23:58 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

int	unit_ft_strcpy_rand(void)
{
	static const int	len = 256;
	char				*src = rand_key(len);
	char				*dst;
	int					diff;

	if (!src || !(dst = malloc(sizeof(*dst) * (len + 1))))
	{
		perror("Error");
		return (1);
	}
	ft_strcpy(dst, src);
	diff = diff_s("return", dst, src);
	free(src);
	free(dst);
	return (!diff);
}

int	unit_ft_strcpy_empty(void)
{
	static const int	len = 0;
	static const char	*src = "";
	char				*dst;
	int					diff;

	dst = malloc(sizeof(*dst) * (len + 1));
	ft_strcpy(dst, src);
	diff = diff_s("return", dst, src);
	free(dst);
	return (!diff);
}

int	unit_ft_strcpy_basic(void)
{
	static const int	len = 13;
	static const char	*src = "Copyright (c)";
	char				*dst;
	int					diff;

	if (!(dst = malloc(sizeof(*dst) * (len + 1))))
	{
		perror("Error");
		return (1);
	}
	ft_strcpy(dst, src);
	diff = diff_s("return", dst, src);
	free(dst);
	return (!diff);
}

int (*tests_ft_strcpy[])(void) = {
	&unit_ft_strcpy_basic,
	&unit_ft_strcpy_empty,
	&unit_ft_strcpy_rand,
	NULL
};
