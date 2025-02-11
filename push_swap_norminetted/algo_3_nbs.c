/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:29:01 by rita              #+#    #+#             */
/*   Updated: 2025/02/10 14:13:03 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	b_node = bigger / highest node value;
	s_node = smallest node value;
*/
void	sort_three_nbs(t_stack **a)
{
	t_stack	*b_node;
	t_stack	*s_node;

	b_node = get_h_node(*a);
	s_node = get_s_node(*a);

	if ((*a) == b_node && (*a)->next == s_node)
		ra(a, false);
	else if ((*a) == b_node && (*a)->next != s_node)
	{
		sa(a, false);
		rra(a, false);
	}
	else if ((*a) == s_node && (*a)->next == b_node)
	{
		sa(a, false);
		ra(a, false);
	}
	else if ((*a) != s_node && (*a) != b_node && (*a)->next == b_node)
		rra(a, false);
	else if ((*a) != s_node && (*a) != b_node && (*a)->next == s_node)
		sa(a, false);
}	
