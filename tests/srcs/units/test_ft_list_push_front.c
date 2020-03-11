#include <tests.h>
#include <stdio.h>

int	test_ft_list_push_front(void)
{
	t_list	*list;
	char	*data;

	list = NULL;
	data = rand_key(4);
	ft_list_push_front(&list, data);
	return (!diff_p(list->data, data) && !diff_p(list->next, NULL));
}
