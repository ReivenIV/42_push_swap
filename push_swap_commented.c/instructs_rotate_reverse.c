/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:18:05 by rita              #+#    #+#             */
/*   Updated: 2025/01/30 15:18:05 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rotate ex : stack = "1,2,3,4,5" => rotate_stack(stack) => "5,1,2,3,4"
static	void rotate_reverse_stack(t_stack **stack)
{
	t_stack *current_node;
	int		stack_len;

	stack_len = get_stack_len(*stack);
	if (*stack == NULL || stack == NULL || stack_len == 1)
		return ;
	current_node = get_last_node(*stack);					// we GET the last node in the stack. 
	current_node->prev->next = NULL;  						// we update the next of the penultimate (before the lastone);
	current_node->next = (*stack);							// new_firstone->next points to second;
	current_node->prev = NULL;								// new_firstone->prev points to NULL;
	(*stack) = current_node;								// update stack with new head
	current_node->next->prev = current_node;				// second node-> points to New first node;
}

void	rra(t_stack **a, bool testing_mode)
{
	rotate_reverse_stack(a);
	if (!testing_mode)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool testing_mode)
{
	rotate_reverse_stack(b);
	if (!testing_mode)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool testing_mode)
{
	rotate_reverse_stack(a);
	rotate_reverse_stack(b);
	if (!testing_mode)
		write(1, "rrr\n", 4);
}

void	rrr_till_cheapest(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	refresh_ids(*a);
	refresh_ids(*b);
}

//*   ---------------------
//*   ::  test it dear   ::
//*  ----------------------
// // int main(void)
// // {
// // 	t_stack *stack = NULL;
// // 	// remember to try with several nodes not only 3.
// // 	push_to_bottom_node(&stack, 1);
// // 	push_to_bottom_node(&stack, 2);
// // 	push_to_bottom_node(&stack, 3);
// // 	push_to_bottom_node(&stack, 4);
// // 	push_to_bottom_node(&stack, 5);
// // 	// Print the stack before rotation
// // 	printf("Stack before rotation: ");
// // 	print_stack(stack);
// // 	// Call rotate_reverse_stack
// // 	rotate_reverse_stack(&stack);
// // 	// Print the stack after rotation
// // 	printf("Stack after rotation: ");
// // 	print_stack(stack);
// // 	return 0;
// // }