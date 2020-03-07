/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_ft_atoi_base.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/03 20:50:28 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/07 19:45:23 by chamada          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int	test_ft_atoi_base(void)
{
	char c = ft_atoi_base("AAAAA", "Abcdef") + '0';
	write(1, &c, 1);
	return (0);
}
