/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:08:22 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/09 14:15:59 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static t_node	*s_new_node(t_edge data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->info.e = data;
	node->next = NULL;
	return (node);
}

t_boolean		s_push(t_stack *root, t_edge data)
{
	t_node *pnew;

	pnew = s_new_node(data);
	if (!pnew)
		return (FALSE);
	pnew->next = *root;
	*root = pnew;
	return (TRUE);
}

t_boolean		is_empty(t_node *root)
{
	return (!root);
}

t_boolean		s_pop(t_stack *root)
{
	t_node *temp;

	if (is_empty(*root))
		return (FALSE);
	temp = *root;
	*root = (*root)->next;
	free(temp);
	return (TRUE);
}

t_edge			s_peek(t_node *root)
{
	return (root->info.e);
}
