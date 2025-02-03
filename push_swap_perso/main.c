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

void print_argv(char **av)
{
    int i = 0;
    while (av[i] != NULL)
    {
        printf("argv[%d]: %s\n", i, av[i]);
        i++;
    }
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))			// if ac doesn't have arguments or If ac has arguments but av is empty
		return (1);
	else if (ac == 2)
	{

		av = ft_split(av[1]);
		//printf("%s", av[0]);

		stack_init(&a, av, ac == 2);
	}
	else
		stack_init(&a, av + 1, false); 				// av + 1 ?

	print_argv(av + 1);								//! just for testing

	print_stack(a);									//! just for testing
	if (!is_stack_sorted(a))
	{
		if (get_stack_len(a) == 2)
			sa(&a, false);
	}
	print_stack(a);									//! just for testing
	return (0);
}
