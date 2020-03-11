#include <tests.h>
#include <stdio.h>

static int	test_cmp(int *a, int *b)
{
	return (*a - *b);
}

static void	test_free(void *data)
{
	*(int*)data = 0;
}

int	test_ft_list_remove_if(void)
{
	t_list				*list;
	int					len;
	int					ref;
	int					got;
	int					pos;
	int					i;

	list = NULL;
	len = ft_rand(0, 32);
	ref = ft_rand(0, UINT32_MAX);
	got = ref;
	pos = ft_rand(0, len);
	i = 0;
	while (i < len)
	{
		if (!(lst_add_front(&list, (i == pos) ? &got : &pos)))
			error();
		i++;
	}
	ft_list_remove_if(&list, &ref, &test_cmp, &test_free);
	return (!diff_i(got, 0) && !diff_p(list, NULL));
}
