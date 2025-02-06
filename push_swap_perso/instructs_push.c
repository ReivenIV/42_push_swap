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
	push_node = (*src);			// assign push node to the first node of src;
	(*src) = (*src)->next;		// src head's updated to the second node (can be a NULL node).
	if (*src)					// if there is a node in src then the new first_one->prev will be NULL
		(*src)->prev = NULL;
	push_node->prev = NULL;		// because p.n. will be the first one in the dest stack then prev = NULL
	if (*dest == NULL)			// If dest is empty
	{
		*dest = push_node;		// update dest heads to push_node
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest; 			// the new-first node -> points to the "head" the first node of dest.
		push_node->next->prev = push_node;	// The new-second node -> prev points to the head.
		*dest = push_node;					// update dest heads to push_node
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

// // int main(void) {
// // 	t_stack *stack_a = NULL;
// // 	t_stack *stack_b = NULL;
// // 	// Initialize stack_a with some values
// // 	push_to_bottom_node(&stack_a, 1);
// // 	push_to_bottom_node(&stack_a, 2);
// // 	push_to_bottom_node(&stack_a, 3);
// // 	push_to_bottom_node(&stack_a, 4);
// // 	push_to_bottom_node(&stack_a, 5);
// // 	push_to_bottom_node(&stack_a, 6);
// // 	// Print initial stacks
// // 	printf("Initial stack_a: ");
// // 	print_stack(stack_a);
// // 	printf("Initial stack_b: ");
// // 	print_stack(stack_b);
// // 	// Perform push operation from stack_a to stack_b
// // 	push(&stack_a, &stack_b);
// // 	// Print stacks after push operation
// // 	printf("After pushing from stack_a to stack_b:\n");
// // 	printf("stack_a: ");
// // 	print_stack(stack_a);
// // 	printf("stack_b: ");
// // 	print_stack(stack_b);
// // 	// Perform another push operation from stack_a to stack_b
// // 	push(&stack_a, &stack_b);
// // 	// Print stacks after second push operation
// // 	printf("After second push from stack_a to stack_b:\n");
// // 	printf("stack_a: ");
// // 	print_stack(stack_a);
// // 	printf("stack_b: ");
// // 	print_stack(stack_b);
// // 	// Free the stacks
// // 	free_stack(&stack_a);
// // 	free_stack(&stack_b);
// // 	return 0;
// // }