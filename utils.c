#include "chainedlist.h"

void	swap_int(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
	return ;
}