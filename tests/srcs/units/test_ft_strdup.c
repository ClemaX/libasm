/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:41:58 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 20:16:06 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

int	unit_ft_strdup_rand(void)
{
	static const int	len = 256;
	char				*src = rand_key(len);
	char				*dst;
	int					diff;

	if (!src || !(dst = ft_strdup(src)))
	{
		perror("Error");
		return (1);
	}
	diff = diff_s("return", dst, src);
	free(src);
	free(dst);
	return (!diff);
}

int	unit_ft_strdup_empty(void)
{
	static const char	*src = "";
	char				*dst;
	int					diff;

	if (!(dst = ft_strdup(src)))
	{
		perror("Error");
		return (1);
	}
	diff = diff_s("return", dst, src);
	free(dst);
	return (!diff);
}

int	unit_ft_strdup_basic(void)
{
	static const char	*src = "Copyright (c)";
	char				*dst;
	int					diff;

	if (!(dst = ft_strdup(src)))
	{
		perror("Error");
		return (1);
	}
	diff = diff_s("return", dst, src);
	free(dst);
	return (!diff);
}

int (*tests_ft_strdup[])(void) = {
	&unit_ft_strdup_basic,
	&unit_ft_strdup_empty,
	&unit_ft_strdup_rand,
	NULL
};
