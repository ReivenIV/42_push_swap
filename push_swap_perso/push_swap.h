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
	int				current_position;
//	int				final_index;
//	int				push_price;
//	bool			above_median;
//	bool			cheapest;
//	struct s_stack	*target_node;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

// Tools  
//* Parsing
char	**ft_split(char const *src);
long	ft_atol(const char *src);

// Error handling
int		syntax_check(char* src);
int		is_nb_in_stack(t_stack *a, int nb);
void	free_stack(t_stack **stack);
void	free_argv(char **argv);
void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2);

// Algos

// XS algo

// XL Algo


#endif