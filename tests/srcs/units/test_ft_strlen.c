/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_strlen.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:41:56 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 18:22:09 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int	test_ft_strlen(void)
{
	char	*str = "Thelengthistwentyone!";

	return (!diff_size(ft_strlen(str), strlen(str)));
}
