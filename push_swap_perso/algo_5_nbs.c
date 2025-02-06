/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:35:59 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 18:35:59 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nbs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack_a == NULL)
		return ;
	refresh_ids(*stack_a);
	smallest_node = get_smallest(*stack_a);
	move_t_to_top(stack_a, smallest_node, 'a');
	sort_four_nbs(stack_a, stack_b);
	pb(stack_b, stack_a, false);
	pb(stack_b, stack_a, false);
}

// // int main(void)
// // {
// //     t_stack *stack_a = NULL;
// //     t_stack *stack_b = NULL;
// //     // Add four random numbers to stack_a
// //     push_to_bottom_node(&stack_a, 300);
// //     push_to_bottom_node(&stack_a, 1);
// //     push_to_bottom_node(&stack_a, 4);
// //     push_to_bottom_node(&stack_a, 2);
// //     push_to_bottom_node(&stack_a, 50);
// //     // Print the stack before sorting
// // 	//print_stack_json(stack_a, 'a');
// // 	//printf("------------------------");
// //     // Sort the stack
// //     sort_five_nbs(&stack_a, &stack_b);
// //     // Print the stack after sorting
// // 	//print_stack_json(stack_a, 'a');
// //     // Free the stacks
// //     free_stack(&stack_a);
// //     free_stack(&stack_b);
// //     return 0;
// // }