#include "../../includes/minishell.h"

t_node	*last_node(t_node *node)
{
	while (node->right)
		node = node->right;
	return (node);
}

void	last_cmd(t_node **node)
{
	t_node	*current;

	if ((*node)->current_cmd && ((*node)->current_pipe))
	{
		current = last_node((*node)->root);
		current->right = (*node)->current_cmd;
		(*node)->current_cmd = NULL;
	}
}