/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:51 by rita              #+#    #+#             */
/*   Updated: 2025/01/30 17:49:51 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void push(t_stack **src, t_stack **dest)
{
	t_stack	*push_node;

	if (*src == NULL)
		return ;
	push_node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}
//			src		  ->	dest
void	pa(t_stack **b, t_stack **a, bool testing_mode)
{
	push(b, a);
	if (!testing_mode)
		write(1, "pa\n", 3);
}
//			src		  ->	dest
void	pb(t_stack **a, t_stack **b, bool testing_mode)
{
	push(a, b);
	if (!testing_mode)
		write(1, "pb\n", 3);
}
