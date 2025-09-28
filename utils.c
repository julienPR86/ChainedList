#include "main.h"

void	swap(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
	return ;
}