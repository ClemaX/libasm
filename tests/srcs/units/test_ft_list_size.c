#include <tests.h>

static t_list	*lst_add_front(t_list **list, char *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->next = *list;
	new->data = data;
	return ((*list = new));
}

int				test_ft_list_size(void)
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
