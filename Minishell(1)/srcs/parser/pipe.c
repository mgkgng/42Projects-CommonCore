#include "../../includes/minishell.h"

void	parse_pipe(t_node **node)
{
	t_node	*new;
	t_node	*tmp;

	new = ft_calloc(1, sizeof(t_node));
	new->node_type = 3;
	new->left = (*node)->current_cmd;
	(*node)->current_cmd = NULL;
	if ((*node)->current_pipe)
	{
		tmp = last_node((*node)->current_pipe);
		tmp->right = new;
	}
	else
	{
		(*node)->current_pipe = new;
		if ((*node)->root->node_type < 3)
			(*node)->root = (*node)->current_pipe;
	}
}