#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_List
{
	int	data;
	struct s_List	*next;
}	t_List;

//Display node's data
void	display_list(t_List *head);
//Return the number of nodes in the list
unsigned int	get_list_length(t_List *head);
//Sort the list in ascending order
//Return NULL on error
t_List	*sort_data(t_List **head);
//Stock the data at index in the data pointer
//Return -1 on error, 0 on success
int	get_data_at_index(t_List *head, unsigned int index, int *data);
//Add a node at the end of the list
//If *head is NULL, the first node will be created
//Return NULL on error
t_List	*add_node(t_List **head, int data);
//Add size nodes since the end of the list
//Return NULL on error
t_List	*add_n_node(t_List **head, int *data, unsigned int size);
//Add a node at index
//Return NULL on error
t_List	*add_node_at_index(t_List **head, int data, unsigned int index);
//Remove the last node of the list
//Return NULL on error
t_List	*remove_node(t_List **head);
//Remove the node at index
//Return NULL on error
t_List	*remove_node_at_index(t_List **head, unsigned int index);
//Remove size nodes from the end of the list
//If you wanna remove all the nodes, size must be equal to 0
//Return NULL on error
t_List	*remove_n_node(t_List **head, unsigned int size);
//Remove all nodes where node's data is equal to rm_data
//Return NULL on error, or if the returned list is empty
t_List *remove_node_data(t_List **head, int rm_data);
//swap to integers
void	swap(int *a, int *b);
#endif