/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:15:24 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/19 16:13:45 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	__ps_rotate(int	*arr, size_t siz);

int	rra(t_stack *stack)
{
	__ps_rotate(stack->dat, stack->cnt);
	ft_putendl_fd("rra", STDOUT_FILENO);
	return (1);
}

int	rrb(t_stack *stack)
{
	__ps_rotate(stack->dat, stack->cnt);
	ft_putendl_fd("rrb", STDOUT_FILENO);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	__ps_rotate(a->dat, a->cnt);
	__ps_rotate(b->dat, b->cnt);
	ft_putendl_fd("rrr", STDOUT_FILENO);
	return (1);
}

static int	__ps_rotate(int	*arr, size_t siz)
{
	int		tmp;

	tmp = arr[siz - 1];
	while (siz-- > 1)
		arr[siz] = arr[siz - 1];
	arr[0] = tmp;
	return (1);
}
