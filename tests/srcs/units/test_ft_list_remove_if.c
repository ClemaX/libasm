#include <tests.h>

static int	test_cmp(int *a, int *b)
{
	return (*a - *b);
}

static void	test_free(void *data)
{
	*(int*)data = 0;
}

static int check_list(t_list *list, void *expected_data, int expected_len)
{
	t_list	*curr;
	int		len;
	int		err;

	curr = list;
	len = 0;
	err = 0;
	while (curr)
	{
		err |= diff_p("data", curr->data, expected_data);
		curr = curr->next;
		len++;
	}
	err |= diff_i("length", len, expected_len);
	return (!err);
}

int	unit_ft_list_remove_if_rand(void)
{
	t_list	*list;
	int		len;
	int		ref;
	int		got;
	int		pos;
	int		i;
	int		diff;

	list = NULL;
	len = ft_rand(1, 256);
	ref = ft_rand(0, UINT32_MAX);
	got = ref;
	pos = ft_rand(0, len);
	i = 0;
	while (i < len)
	{
		if (!(lst_add_front(&list, (i == pos) ? &got : &pos)))
			perror("Error");
		i++;
	}
	ft_list_remove_if(&list, &ref, &test_cmp, &test_free);
	diff = diff_i("data was not removed", got, 0);
	diff += !check_list(list, &pos, len - 1);
	lst_clear(&list);
	return (!diff);
}

int (*tests_ft_list_remove_if[])(void) = {
	&unit_ft_list_remove_if_rand,
	NULL
};
