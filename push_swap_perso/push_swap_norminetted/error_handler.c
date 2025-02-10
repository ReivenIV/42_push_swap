/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:28:04 by rita              #+#    #+#             */
/*   Updated: 2025/01/27 14:28:04 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* Will check src is a (char*)numbers. 
// if valid, TRUE/1
// if not valid, FALSE/0
int	is_syntax_correct(char* src)
{
	int i;
	
	i = 0;
	if (src == NULL)
		return (0);
	if (!(src[0] == '+' || src[0] == '-' || (src[0] >= '0' && src[0] <= '9')))
		return (0);
	if ((src[0] == '+' ||  src[0] == '-') && !(src[1] >= '0' && src[1] <= '9'))
		return (0);
	if ((src[0] == '+' ||  src[0] == '-') && (src[1] >= '0' && src[1] <= '9'))
		i++;
	while (src[i] != '\0')
	{
		if (!(src[i] >= '0' && src[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

int	is_nb_in_stack(t_stack *a, int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

//* will free a stack of nodes.
void	free_stack(t_stack **stack)
{
	t_stack	*tmp_node;
	t_stack *current_node;

	if (stack == NULL)
		return ;
	current_node = *stack;
	while (current_node)
	{
		tmp_node = current_node->next;
		free(current_node);
		current_node = tmp_node;
	}
	*stack = NULL;
	return ;
}

//* Will free all elements in argv and argv itself
void	free_argv(char **av, bool is_ac_2)
{
	int i;

	i = 0;
	while(av[i])
	{
		free(av[i]);
		i++;
	}
	if (is_ac_2 == true)
		free(av);
}

// Will free all the stack and if argc was only 2 (known by 1/0 TRUE/FALSE) will free all argv aswell
void	free_handler(t_stack **a_or_b, char **argv, bool flag_argc_2)
{
	free_stack(a_or_b);

	if (flag_argc_2)
		free_argv(argv, true);
	write(2, "Error\n", 6);
	exit(1);
}
