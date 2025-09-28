#include "main.h"

t_Node	*add_node(t_Node **head, int data)
{
	t_Node *cpy;

	if (NULL == head)
		return (NULL);
	if (NULL == *head)
	{
		*head = (t_Node *)malloc(sizeof(t_Node));
		if (NULL == *head)
			return (NULL);
		(*head)->data = data;
		(*head)->next = NULL;
		return (*head);
	}
	cpy = *head;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = (t_Node *)malloc(sizeof(t_Node));
	if (NULL == cpy->next)
		return (NULL);
	cpy->next->data = data;
	cpy->next->next = NULL;
	return (*head);
}

t_Node	*add_n_node(t_Node **head, int *data, unsigned int size)
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

t_Node	*add_node_at_index(t_Node **head, int data, unsigned int index)
{
	t_Node	*node;
	t_Node	*cpy;
	unsigned int	indice = 0;

	if (NULL == head)
		return (NULL);
	if (index >= get_list_length(*head))
	{
		printf("Index out of range\n");
		return (NULL);
	}
	node = (t_Node *)malloc(sizeof(t_Node));
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