#include "main.h"

t_Node	*remove_node(t_Node **head)
{
	t_Node	*cpy;

	if (NULL == head || NULL == *head)
		return (NULL);
	if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
		return (NULL);
	}
	cpy = *head;
	while (cpy->next->next)
		cpy = cpy->next;
	free(cpy->next);
	cpy->next = NULL;
	return (*head);
}

t_Node	*remove_n_node(t_Node **head, unsigned int size)
{
	unsigned int	index = 0;

	if (NULL == head)
		return (NULL);
	while (index < size || size == 0)
	{
		if (NULL == remove_node(head))
			return (NULL);
		index++;
	}
	return (*head);
}

t_Node	*remove_node_at_index(t_Node **head, unsigned int index)
{
	t_Node	*cpy;
	t_Node	*save;
	unsigned int	indice = 0;

	if (NULL == head)
		return (NULL);
	if (index >= get_list_length(*head))
	{
		printf("Index out of range\n");
		return (NULL);
	}
	if (index == 0)
	{
		save = (*head)->next;
		free(*head);
		*head = save;
		return (*head);
	}
	cpy = *head;
	while (cpy->next && indice < index - 1)
	{
		cpy = cpy->next;
		indice++;
	}
	save = cpy->next->next;
	free(cpy->next);
	cpy->next = save;
	return (*head);
}

t_Node	*remove_node_data(t_Node **head, int rm_data)
{
	t_Node	*cpy;
	t_Node	*save;

	if (NULL == head || NULL == *head)
		return (NULL);

	cpy = *head;
	while (cpy->next)
	{
		if (rm_data == cpy->next->data)
		{
			save = cpy->next;
			cpy->next = cpy->next->next;
			free(save);
		}
		else
			cpy = cpy->next;
	}
	if (rm_data == (*head)->data)
	{
		if (NULL == (*head)->next)
		{
			free(*head);
			*head = NULL;
			return (NULL);
		}
		save = (*head)->next;
		free(*head);
		*head = save;
	}
	return (*head);
}