#include "chainedlist.h"

unsigned int	lst_get_list_length(t_List *head)
{
	int	size = 0;

	while (head)
	{
		size += 1;
		head = head->next;
	}
	return (size);
}