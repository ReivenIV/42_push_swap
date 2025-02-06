#include "push_swap.h"
#include <assert.h>

//* test_refresh_ids
void test_refresh_ids() {
    // Create a sample stack
    t_stack *stack = create_new_node(10);
    stack->next = create_new_node(20);
    stack->next->prev = stack;
    stack->next->next = create_new_node(30);
    stack->next->next->prev = stack->next;

    // Call refresh_ids
    refresh_ids(stack);

    // Verify the ids and is_above_median values
    t_stack *current = stack;
    int expected_ids[] = {0, 1, 2};
    bool expected_medians[] = {true, true, false};
    for (int i = 0; i < 3; i++) {
        assert(current->id == expected_ids[i]);
        assert(current->is_above_median == expected_medians[i]);
        current = current->next;
    }
    // Free the stack
    free_stack(&stack);
}

void test_refresh_targets_node() {
    // Create sample stacks
    t_stack *stack_a = create_new_node(10);
    stack_a->next = create_new_node(20);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_new_node(30);
    stack_a->next->next->prev = stack_a->next;

    t_stack *stack_b = create_new_node(15);
    stack_b->next = create_new_node(25);
    stack_b->next->prev = stack_b;

    // Call refresh_targets_node
    refresh_targets_node(stack_a, stack_b);

    // Verify the target nodes
    assert(stack_b->target_node == stack_a->next); // 15 should target 20
    assert(stack_b->next->target_node == stack_a->next->next); // 25 should target 30

    // Free the stacks
    free_stack(&stack_a);
    free_stack(&stack_b);
}

void test_set_prices() {
    // Create sample stacks
    t_stack *stack_a = create_new_node(10);
    stack_a->next = create_new_node(20);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_new_node(30);
    stack_a->next->next->prev = stack_a->next;

    t_stack *stack_b = create_new_node(15);
    stack_b->next = create_new_node(25);
    stack_b->next->prev = stack_b;
	// stack_b->next->next = NULL;
	// stack_b->next->next->prev = stack_b->next;

	refresh_ids(stack_a);
	refresh_ids(stack_b);
	refresh_targets_node(stack_a, stack_b);				// without target you will have a segment fault
    set_prices(stack_a, stack_b);						// Call set_prices

    // Verify the push prices
    assert(stack_b->push_price == 1); // 15 should have a push price of 1
    assert(stack_b->next->push_price == 2); // 25 should have a push price of 2

    // Free the stacks
    free_stack(&stack_a);
    free_stack(&stack_b);
}

void test_flag_cheapest() {
    // Create sample stacks
    t_stack *stack_a = create_new_node(10);
    stack_a->next = create_new_node(20);
    stack_a->next->prev = stack_a;
    stack_a->next->next = create_new_node(30);
    stack_a->next->next->prev = stack_a->next;

    t_stack *stack_b = create_new_node(15);
    stack_b->next = create_new_node(25);
    stack_b->next->prev = stack_b;
	print_stack_json(stack_b, 'b');
    printf("-------------------------\n");
    printf("-------------------------\n");
    printf("-------------------------\n");

    // Refresh data and set prices
    refresh_ids(stack_a);
    refresh_ids(stack_b);
    refresh_targets_node(stack_a, stack_b);
    set_prices(stack_a, stack_b);

    // Call flag_cheapest
    flag_cheapest(stack_b);

	print_stack_json(stack_a, 'a');
    printf("-------------------------\n");

	print_stack_json(stack_b, 'b');
    // Verify the cheapest node
    assert(stack_b->is_cheapest == true);				// 15 should be flagged as cheapest
    assert(stack_b->next->is_cheapest == false);		// 25 should not be flagged as cheapest

    // Free the stacks
    free_stack(&stack_a);
    free_stack(&stack_b);
}

// Will test all function in present f
int main() {
    test_refresh_ids();
    test_refresh_targets_node();
    test_set_prices();
	test_flag_cheapest();
    printf("All tests passed!\n");
    return 0;
}