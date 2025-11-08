#include "main.h"

int	get_data_at_index(t_List *head, unsigned int index, int *data)
{
	t_List	*cpy;
	unsigned int	indice = 0;

	if (NULL == head)
	{
		printf("List is empty\n");
		return (-1);
	}
	if (index >= get_list_length(head))
	{
		printf("Index out of range\n");
		return (-1);
	}
	cpy = head;
	while (indice < index)
	{
		cpy = cpy->next;
		indice++;
	}
	*data = cpy->data;
	return (0);
}

t_List	*sort_data(t_List **head)
{
	t_List	*cpy;
	int		len;
	int		index = 0;

	if (NULL == head || NULL == *head)
		return (NULL);
	len = get_list_length(*head);
	while (index < len)
	{
		cpy = *head;
		while (cpy->next)
		{
			if (cpy->data > cpy->next->data)
				swap(&cpy->data, &cpy->next->data);
			cpy = cpy->next;
		}
		index++;
	}
	return (*head);
}