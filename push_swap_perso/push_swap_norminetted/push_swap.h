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
	int				id;
	bool			is_above_median;
	int				push_price;
	bool			is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// Tools for testing :
void print_argv(char **av);									//! --> for testing
void	print_stack(t_stack *stack);					//! --> for testing


void print_stack_json(t_stack *stack, char c);
void print_argv(char **av);

// Tools  
//* Parsing
char	**ft_split(const char *str);
long	ft_atol(const char *src);
void	stack_init(t_stack **stack_a, char **argv, bool is_argc_2);

// Error handling
int		is_syntax_correct(char* src);
int		is_nb_in_stack(t_stack *a, int nb);
void	free_stack(t_stack **stack);
void	free_argv(char **argv, bool is_ac_2);
void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2);

//		-------------
//		::  tools  ::
//		-------------
// tools Stack-node
t_stack	*create_new_node(int value);					
void	push_to_top_node(t_stack **stack, int value);
void	push_to_bottom_node(t_stack **stack, int value);
int		is_stack_sorted(t_stack *stack);

// tools_get_stack
t_stack	*get_smallest(t_stack *stack);
int		get_stack_len(t_stack *stack);
t_stack	*get_last_node(t_stack	*head_node);
t_stack	*get_cheapest(t_stack *stack);

// tools_move_stack
void	move_t_to_top(t_stack **stack, t_stack *target_node, char s_group);
void	move_cheapest(t_stack **a, t_stack **b);

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
void	rr_till_cheapest(t_stack **a, t_stack **b, t_stack *cheapest_node);
// Reverse-rotate
void	rra(t_stack **a, bool testing_mode);
void	rrb(t_stack **b, bool testing_mode);
void	rrr(t_stack **a, t_stack **b, bool testing_mode);
void	rrr_till_cheapest(t_stack **a, t_stack **b, t_stack *cheapest_node);
// Swap
void	sa(t_stack **a, bool testing_mode);
void	sb(t_stack **b, bool testing_mode);
void	ss(t_stack **a, t_stack **b, bool testing_mode);
// Push
void	pa(t_stack **b, t_stack **a, bool testing_mode);
void	pb(t_stack **a, t_stack **b, bool testing_mode);

// sort_3 tools
t_stack	*get_h_node(t_stack *stack);
t_stack	*get_s_node(t_stack *stack);

//		------------
//		::  Algos ::
//		------------
void	algo_handler(t_stack **stack_a, t_stack **stack_b);
void	sort_three_nbs(t_stack **a);
void	sort_four_nbs(t_stack **stack_a, t_stack **stack_b);
void	sort_five_nbs(t_stack **stack_a, t_stack **stack_b);
void	sort_random_amount(t_stack **stack_a, t_stack **stack_b, int len_a);

#endif