#include <tests.h>

int	unit_ft_list_size_rand(void)
{
	t_list	*list;
	int		expected;
	int		i;

	list = NULL;
	expected = ft_rand(0, 15);
	i = expected;
	while (i--)
		lst_add_front(&list, NULL);
	i = ft_list_size(list);
	return (!diff_i(i, expected));
}

int (*tests_ft_list_size[])(void) = {&unit_ft_list_size_rand, NULL};
