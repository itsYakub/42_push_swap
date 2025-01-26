/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:07:17 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/23 08:33:39 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "libft/libft.h"

static int	__ps_single_arg(t_stack *s, char *av);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (1);
	else if (ac == 2)
	{
		if (!__ps_single_arg(&a, av[1]))
			return (write(STDERR_FILENO, "Error\n", 6));
	}
	else
	{
		ps_stack(&a, ac - 1);
		if (!ps_fill(&a, av + 1))
		{
			ps_free(&a);
			return (write(STDERR_FILENO, "Error\n", 6));
		}
	}
	ps_stack(&b, a.siz);
	push_swap(&a, &b);
	ps_free(&a);
	ps_free(&b);
	return (0);
}

int	push_swap(t_stack *a, t_stack *b)
{
	if (!ps_issorted(*a))
	{
		if (a->cnt <= 3)
		{
			while (!ps_issorted(*a))
				ps_sort3(a);
		}
		else
		{
			ps_sort_atob(a, b);
			while (!ps_issorted(*a))
				ps_sort3(a);
			ps_sort_btoa(a, b);
		}
	}
	return (1);
}

int	ps_issorted(t_stack stack)
{
	while (stack.cnt-- > 1)
	{
		if (stack.dat[stack.cnt] < stack.dat[stack.cnt - 1])
			return (0);
	}
	return (1);
}

static int	__ps_single_arg(t_stack *s, char *av)
{
	char	**split;

	split = ft_split(av, ' ');
	if (!split)
		return (0);
	ps_stack(s, ft_arrsiz2d((void **) split));
	if (!ps_fill(s, split))
	{
		ft_free2d((void **) split);
		ps_free(s);
		return (0);
	}
	ft_free2d((void **) split);
	return (1);
}
