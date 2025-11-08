#include "main.h"

t_List	*add_node(t_List **head, int data)
{
	t_List *cpy;

	if (NULL == head)
		return (NULL);
	if (NULL == *head)
	{
		*head = (t_List *)malloc(sizeof(t_List));
		if (NULL == *head)
			return (NULL);
		(*head)->data = data;
		(*head)->next = NULL;
		return (*head);
	}
	cpy = *head;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = (t_List *)malloc(sizeof(t_List));
	if (NULL == cpy->next)
		return (NULL);
	cpy->next->data = data;
	cpy->next->next = NULL;
	return (*head);
}

t_List	*add_n_node(t_List **head, int *data, unsigned int size)
{
	unsigned int	index = 0;

	if (NULL == head)
		return (NULL);
	while (index < size)
	{
		if (NULL == add_node(head, *(data + index)))
		{
			remove_n_node(head, index);
			return (NULL);
		}
		index++;
	}
	return (*head);
}

t_List	*add_node_at_index(t_List **head, int data, unsigned int index)
{
	t_List	*node;
	t_List	*cpy;
	unsigned int	indice = 0;

	if (NULL == head)
		return (NULL);
	if (index >= get_list_length(*head))
	{
		printf("Index out of range\n");
		return (NULL);
	}
	node = (t_List *)malloc(sizeof(t_List));
	node->data = data;
	if (index == 0)
	{
		node->next = *head;
		*head = node;
		return (*head);
	}
	cpy = *head;
	while (indice < index -1)
	{
		cpy = cpy->next;
		indice++;
	}
	node->next = cpy->next;
	cpy->next = node;
	return (*head);
}