/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:05:27 by yorlians          #+#    #+#             */
/*   Updated: 2023/05/31 07:36:50 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	get and return the number of nodes
		(size) in a linked list.
*/
int	stack_size(t_stack *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*
	add new node at the end of a linked list.
*/
void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/*
	add new node at the front of a linked list.
*/
void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
	find last node in linked list.
*/
t_stack	*stack_last(t_stack *lst)
{
	while (lst)
	{	
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
	create a new node for a stack.
*/
t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}
