#include "chainedlist.h"

int	main()
{
	t_List	*head = NULL;
	int data_save;
	int	data[] = {9, 17, 23, 12, 35};
	//Adds five nodes that contains each one element of data
	lst_add_n_node(&head, data, 5);
	lst_display_list(head);
	//Saves the node data at index 2
	lst_get_data_at_index(head, 2, &data_save);
	//Removes the node a the index 2
	lst_remove_node_at_index(&head, 2);
	lst_display_list(head);
	//Put the saved data at the beginning of the list
	lst_add_node_at_index(&head, data_save, 0);
	lst_display_list(head);
	//Sort the data
	lst_sort_data(&head);
	lst_display_list(head);
	//Removes all the nodes, to free the list
	lst_remove_n_node(&head, 0);
	lst_display_list(head);
	return (0);
}