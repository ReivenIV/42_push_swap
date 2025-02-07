/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_4_nbs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:47:28 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 16:47:28 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_nbs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack_a == NULL)
		return ;
	refresh_ids(*stack_a);
	smallest_node = get_smallest(*stack_a);
	move_t_to_top (stack_a, smallest_node, 'a');
	pb(stack_a, stack_b, false);
	sort_three_nbs(stack_a);
	pa(stack_b, stack_a, false);
}

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------

// // int main(void)
// // {
// //     t_stack *stack_a = NULL;
// //     t_stack *stack_b = NULL;
// //     // Add four random numbers to stack_a
// //     push_to_bottom_node(&stack_a, 300);
// //     push_to_bottom_node(&stack_a, 1);
// //     push_to_bottom_node(&stack_a, 4);
// //     push_to_bottom_node(&stack_a, 2);
// //     // Print the stack before sorting
// // 	//print_stack_json(stack_a, 'a');
// // 	//printf("------------------------");
// //     // Sort the stack
// //     sort_four_nbs(&stack_a, &stack_b);
// //     // Print the stack after sorting
// // 	//print_stack_json(stack_a, 'a');
// //     // Free the stacks
// //     free_stack(&stack_a);
// //     free_stack(&stack_b);
// //     return 0;
// // }