/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:13:58 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/19 14:57:21 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	__ps_rotate(int	*arr, size_t siz);

int	ra(t_stack *stack)
{
	__ps_rotate(stack->dat, stack->cnt);
	ft_putendl_fd("ra", STDOUT_FILENO);
	return (1);
}

int	rb(t_stack *stack)
{
	__ps_rotate(stack->dat, stack->cnt);
	ft_putendl_fd("rb", STDOUT_FILENO);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	__ps_rotate(a->dat, a->cnt);
	__ps_rotate(b->dat, b->cnt);
	ft_putendl_fd("rr", STDOUT_FILENO);
	return (1);
}

static int	__ps_rotate(int	*arr, size_t siz)
{
	int		iter;
	int		tmp;

	tmp = arr[0];
	iter = -1;
	while (++iter < (int) siz)
		arr[iter] = arr[iter + 1];
	arr[siz - 1] = tmp;
	return (1);
}
