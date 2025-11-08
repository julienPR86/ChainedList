#include "chainedlist.h"

void	lst_display_list(t_List *head)
{
	if (NULL == head)
	{
		printf("List is empty\n");
		return ;
	}
	while (head)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("null\n");
	return ;
}