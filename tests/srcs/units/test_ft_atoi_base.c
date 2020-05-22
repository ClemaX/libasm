/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:50:28 by chamada           #+#    #+#             */
/*   Updated: 2020/05/21 20:29:13 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

int	unit_ft_atoi_base_error_base_space(void)
{
	static const int	expected = 0;
	int					got;
	int					diff;

	got = ft_atoi_base("111", "01\t2");
	diff = diff_i("base: 01\\t2 return", got, expected);
	got = ft_atoi_base("11", "01\r2");
	diff += diff_i("base: 01\\r2 return", got, expected);
	got = ft_atoi_base("1", "01 2");
	diff += diff_i("base: 01 2 return", got, expected);
	got = ft_atoi_base("1", "01\n2");
	diff += diff_i("base: 01\\n2 return", got, expected);
	return (!diff);
}


int	unit_ft_atoi_base_error_base_signs(void)
{
	static const int	expected = 0;
	int					got;
	int					diff;

	got = ft_atoi_base("11", BASE_PLUS);
	diff = diff_i("base: "BASE_PLUS" return", got, expected);
	got = ft_atoi_base("1", BASE_MINUS);
	diff += diff_i("base: "BASE_MINUS" return", got, expected);
	return (!diff);
}

int	unit_ft_atoi_base_error_base_len(void)
{
	static const char	*base = "0";
	static const int	expected = 0;
	int					got;

	got = ft_atoi_base("1", base);
	return (!diff_i("invalid base return", got, expected));
}

int	unit_ft_atoi_base_error_base_dup(void)
{
	static const char	*base = "012341";
	static const int	expected = 0;
	int					got;

	got = ft_atoi_base("1", base);
	return (!diff_i("invalid base return", got, expected));
}

int	unit_ft_atoi_base_rand_hex(void)
{
	static const int	len = 32;
	char				src[len];
	int					dest;
	int					rand;

	rand = ft_rand(0, 0xffffffff);
	snprintf(src, len, "\r \t-+-%X", rand);
	dest = ft_atoi_base(src, BASE_HEX);
	return (!diff_i("hex return", dest, rand));
}

int	unit_ft_atoi_base_empty(void) {
	static const int	expected = 0;
	int					got;
	int					diff;

	got = ft_atoi_base("", "01234");
	diff = diff_i("empty string return", got, expected);
	got = ft_atoi_base("01234", "");
	diff += diff_i("empty base return", got, expected);
	got = ft_atoi_base("", "");
	diff += diff_i("empty strings return", got, expected);
	return (!diff);
}

int (*tests_ft_atoi_base[])(void) = {
	&unit_ft_atoi_base_empty,
	&unit_ft_atoi_base_rand_hex,
	&unit_ft_atoi_base_error_base_dup,
	&unit_ft_atoi_base_error_base_len,
	&unit_ft_atoi_base_error_base_signs,
	&unit_ft_atoi_base_error_base_space,
	NULL
};
