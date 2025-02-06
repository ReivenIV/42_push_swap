/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:28:11 by rita              #+#    #+#             */
/*   Updated: 2025/01/27 14:28:11 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>   //! <--
# include <stdlib.h>
# include <stdbool.h> //* <--
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				id;									// current order of nodes (will be updated in every move)
	bool			is_above_median;					// in the stack is it above the the middle of the stack ? 
// //	int				final_index;
	int				push_price;							// aprox how many moves will be needed to move the node
	bool			is_cheapest;							// is it the cheapest node to be moved ? 
	struct s_stack	*target_node;						// the best possible following node
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// Tools for testing :
void print_argv(char **av);									//! --> for testing
void print_stack_json(t_stack *stack, char c);
void print_argv(char **av);

// Tools  
//* Parsing
char	**ft_split(char const *src);
long	ft_atol(const char *src);
void	stack_init(t_stack **stack_a, char **argv, bool is_argc_2);

// Error handling
int		is_syntax_correct(char* src);					// return BOOl.
int		is_nb_in_stack(t_stack *a, int nb);				// return BOOl.
void	free_stack(t_stack **stack);
void	free_argv(char **argv, bool is_ac_2);
void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2);

//		-------------
//		::  tools  ::
//		-------------
// tools Stack-node
void	print_stack(t_stack *stack);					//! --> for testing
t_stack	*create_new_node(int value);					
void	push_to_top_node(t_stack **stack, int value);
void	push_to_bottom_node(t_stack **stack, int value);
int		is_stack_sorted(t_stack *stack);

// tools_get_stack
t_stack	*get_smallest(t_stack *stack);
int		get_stack_len(t_stack *stack);
t_stack	*get_last_node(t_stack	*head_node);

// tools_move_stack
void	move_t_to_top(t_stack **stack, t_stack *target_node, char s_group);

// tools in stack-nodes-data
void	refresh_ids(t_stack	*stack);
void	refresh_targets_node(t_stack *stack_a, t_stack *stack_b);
void	set_prices(t_stack *a, t_stack *b);
void	flag_cheapest(t_stack *b);
void	refresh_nodes_data(t_stack *a, t_stack *b);

//		--------------------
//		::  Instructions  ::
//		--------------------
// Rotate:
void	ra(t_stack **a, bool testing_mode);
void	rb(t_stack **b, bool testing_mode);
void	rr(t_stack **a, t_stack **b, bool testing_mode);
// Reverse-rotate
void	rra(t_stack **a, bool testing_mode);
void	rrb(t_stack **b, bool testing_mode);
void	rrr(t_stack **a, t_stack **b, bool testing_mode);
// Swap
void	sa(t_stack **a, bool testing_mode);
void	sb(t_stack **b, bool testing_mode);
void	ss(t_stack **a, t_stack **b, bool testing_mode);
// Push
void	pa(t_stack **b, t_stack **a, bool testing_mode);
void	pb(t_stack **a, t_stack **b, bool testing_mode);

//		------------
//		::  Algos ::
//		------------
// XS algo
t_stack	*get_h_node(t_stack *stack);
t_stack	*get_s_node(t_stack *stack);

// XL Algo
void	sort_three_nbs(t_stack **a);



#endif