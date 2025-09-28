#include "main.h"

int	main()
{
	t_Node	*head = NULL;
	int data_save;
	int	data[] = {9, 17, 23, 12, 35};
	//Adds five nodes that contains each one element of data
	add_n_node(&head, data, 5);
	display_list(head);
	//Saves the node data at index 2
	get_data_at_index(head, 2, &data_save);
	//Removes the node a the index 2
	remove_node_at_index(&head, 2);
	display_list(head);
	//Put the saved data at the beginning of the list
	add_node_at_index(&head, data_save, 0);
	display_list(head);
	//Sort the data
	sort_data(&head);
	display_list(head);
	//Removes all the nodes, to free the list
	remove_n_node(&head, 0);
	display_list(head);
	return (0);
}