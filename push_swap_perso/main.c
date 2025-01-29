/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:53:39 by rita              #+#    #+#             */
/*   Updated: 2025/01/23 15:53:39 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))		//if ac doesn't have arguments or If ac has arguments but av is empty
		return (1);
	else if (ac == 2)
		av = ft_split(av[1]);
	stack_init(&a, av, ac == 2); 				//! av + 1 ?
	print_stack(a);								//! just for testing
	if (!is_stack_sorted(a))
		printf("error, not sorted");
	if (is_stack_sorted(a))
		printf("Stack sorted");
	return (0);
}