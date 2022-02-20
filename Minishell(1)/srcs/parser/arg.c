#include "../../includes/minishell.h"

char	**arg_begin(char *s)
{
	char	**new;

	new = malloc(sizeof(char *) * 2);
	new[0] = s;
	new[1] = NULL;
	return (new);
}

void	arg_join(t_node **node, char *join)
{
	int		i;
	int 	count;
	char	**new;

	i = -1;
	count = 0;
	while ((*node)->current_cmd->left->args[++i])
		count++;
	new = malloc(sizeof(char *) * (count + 2));
	i = -1;
	while ((*node)->current_cmd->left->args[++i])
		new[i] = (*node)->current_cmd->left->args[i];
	new[i++] = join;
	new[i] = NULL;
	free((*node)->current_cmd->left->args);
	(*node)->current_cmd->left->args = new;
}

void	parse_cmd(t_node **node, char *new_arg)
{
	t_node	*new;

	if ((*node)->current_cmd)
		arg_join(node, new_arg);
	else
	{
		new = ft_calloc(1, sizeof(t_node));
		new->node_type = 2;
		new->left = ft_calloc(1, sizeof(t_node));
		new->left->node_type = 0;
		new->left->args = arg_begin(new_arg);
		(*node)->current_cmd = new;
		if (!(*node)->root)
			(*node)->root = new;
	}
}