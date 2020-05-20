/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/26 16:34:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/11 17:07:13 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <tests.h>

int		run_tests(char *label, int (*tests[])(void))
{
	int	ret;
	int err;
	int i;

	printf("%s %*s\t",
		BULLET, LBL_FW, label);
	i = 0;
	err = 0;
	while (tests[i])
	{
		ret = (*tests[i])();
		printf(ret ? PASS : FAIL);
		err += !ret;
		i++;
		if (tests[i])
			printf(" ");
	}
	printf("\n");
	return (!err);
}

t_list	*lst_add_front(t_list **list, void *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->data = data;
	new->next = *list;
	return ((*list = new));
}
