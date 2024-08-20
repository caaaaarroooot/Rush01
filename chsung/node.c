#include "universal.h"

t_node	*new_node(void)
{
	int		i;
	int		j;
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	n->prev = NULL;
	n->next = NULL;
	i = -1;
	j = -1;
	while (++i < MAX_SIZE)
	{
		while (++j < MAX_SIZE)
		{
			n->board[i][j] = 0;
		}
	}
	return (n);
}
