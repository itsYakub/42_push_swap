/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:06:18 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/26 12:28:30 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	sa(t_stack *stack)
{
	int	tmp;

	if (stack->cnt < 2)
		return (0);
	tmp = stack->dat[0];
	stack->dat[0] = stack->dat[1];
	stack->dat[1] = tmp;
	ft_putendl_fd("sa", STDOUT_FILENO);
	return (1);
}

int	sb(t_stack *stack)
{
	int	tmp;

	if (stack->cnt < 2)
		return (0);
	tmp = stack->dat[0];
	stack->dat[0] = stack->dat[1];
	stack->dat[1] = tmp;
	ft_putendl_fd("sb", STDOUT_FILENO);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->cnt < 2 || b->cnt < 2)
		return (0);
	tmp = a->dat[0];
	a->dat[0] = a->dat[1];
	a->dat[1] = tmp;
	tmp = b->dat[0];
	b->dat[0] = b->dat[1];
	b->dat[1] = tmp;
	ft_putendl_fd("ss", STDOUT_FILENO);
	return (1);
}
