#include <tests.h>

int	unit_ft_list_push_front_basic(void)
{
	t_list	*list;
	char	*data;
	int		diff;

	list = NULL;
	data = rand_key(4);
	ft_list_push_front(&list, data);
	if (!list)
	{
		perror("Error");
		return (1);
	}
	diff = diff_p(list->data, data);
	diff += diff_p(list->next, NULL);
	return (!diff);
}

int (*tests_ft_list_push_front[])(void) = {&unit_ft_list_push_front_basic, NULL};
