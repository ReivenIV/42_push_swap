/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:44:04 by rita              #+#    #+#             */
/*   Updated: 2025/02/11 13:52:54 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_handler(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_length;

	stack_a_length = get_stack_len(*stack_a);
	if (stack_a_length == 2)
		sa(stack_a);
	else if (stack_a_length == 3)
		sort_three_nbs(stack_a);
	else if (stack_a_length == 4)
		sort_four_nbs(stack_a, stack_b);
	else if (stack_a_length == 5)
		sort_five_nbs(stack_a, stack_b);
	else if (stack_a_length > 5)
		sort_random_amount(stack_a, stack_b, stack_a_length);
}
