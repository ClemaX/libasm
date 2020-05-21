/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:42:00 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 17:41:49 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <tests.h>

int	unit_ft_strcmp_rand(void)
{
	static const int	max_len = 256;
	char				*src;
	char				*dst;
	int					diff;
	int					err;

	src = rand_key(ft_rand(0, max_len));
	dst = rand_key(ft_rand(0, max_len));
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

int	unit_ft_strcmp_empty(void)
{
	static const char	*src = "";
	static const char	*dst = "";

	return (!diff_bool("sign", ft_strcmp(dst, src) < 0, strcmp(dst, src) < 0));
}

int (*tests_ft_strcmp[])(void) = {
	&unit_ft_strcmp_empty,
	&unit_ft_strcmp_rand,
	NULL
};
