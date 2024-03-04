#include "include/main.h"

void	lst_clean(t_date_exc first)
{
	t_date_exc *current = first;
	t_date_exc *next = 0;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_date_exc lst_last(t_date_exc first)
{
	if (!first)
		return (0);
	while(first->next != 0)
	{
		first = first->next;
	}
	return (first);
}

