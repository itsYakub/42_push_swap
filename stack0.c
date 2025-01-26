/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:06:23 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/22 11:22:19 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ps_stack(t_stack *stack, size_t len)
{
	stack->siz = len;
	stack->dat = ft_calloc(len, sizeof(int));
	if (!stack->dat)
		return (0);
	stack->cnt = 0;
	return (1);
}

int	ps_fill(t_stack *s, char **av)
{
	while (*av)
	{
		if (!ps_validate(s, *av))
			return (0);
		s->dat[s->cnt++] = ft_atoi(*av);
		av++;
	}
	return (1);
}

int	ps_free(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->dat)
	{
		free(stack->dat);
	}
	return (1);
}
