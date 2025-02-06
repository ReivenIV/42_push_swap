/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:57 by rita              #+#    #+#             */
/*   Updated: 2025/02/06 14:20:57 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print all nodes in a stack in JSON format
// Super f*** usefull. It's a keeper these function. 
void print_stack_json(t_stack *stack, char c) {
    t_stack *current = stack;
	if (c == 'a')
    	printf("stack_A:");
	else
    	printf("stack_B:");

    printf("[\n");
    while (current != NULL) {
        printf("  {\n");
        printf("    \"value\": %d,\n", current->value);
        printf("    \"id\": %d,\n", current->id);
        printf("    \"is_above_median\": %s,\n", current->is_above_median ? "true" : "false");
        printf("    \"push_price\": %i,\n", current->push_price);
        printf("    \"is_cheapest\": %s,\n", current->is_cheapest ? "true" : "false");
        if (current->target_node != NULL) {
            printf("    \"target_node\": {\n");
            printf("      \"value\": %d,\n", current->target_node->value);
            printf("      \"id\": %d\n", current->target_node->id);
            printf("    }\n");
        } else {
            printf("    \"target_node\": null\n");
        }
        printf("  }");
        if (current->next != NULL) {
            printf(",");
        }
        printf("\n");
        current = current->next;
    }
    printf("]\n");
}

//* Function to print all elements in the stack
void print_stack(t_stack *stack)  			//! FOR TESTING ONLY 
{
    t_stack *current;

	current = stack;
	printf("stack :: ");
    while (current != NULL)
    {
        printf("%d ", current->value);		//! PRINTF
        current = current->next;
    }
    printf("\n");							//! PRINTF
}
