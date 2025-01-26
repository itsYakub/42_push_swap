/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:21:56 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/23 11:54:26 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	__ps_dest_low(t_stack *dest, int val);
static int	__ps_dest_high(t_stack *dest, int val);

int	ps_sort3(t_stack *a)
{
	if (a->dat[0] > a->dat[1])
	{
		if (a->dat[0] < a->dat[2])
			sa(a);
		else
			ra(a);
	}
	else
		rra(a);
	return (1);
}

int	ps_dest_in_stack(t_stack *dest, int val, char mod)
{
	if (mod == 'b')
		return (__ps_dest_high(dest, val));
	else if (mod == 'a')
		return (__ps_dest_low(dest, val));
	return (0);
}

static int	__ps_dest_low(t_stack *dest, int val)
{
	size_t	iter;

	iter = -1;
	while (++iter < dest->cnt - 1)
	{
		if (val > dest->dat[iter])
		{
			if (val < dest->dat[iter + 1])
				return (iter + 1);
			else if (dest->dat[iter + 1] == ps_lowest(*dest))
				return (iter + 1);
		}
		else if (val < ps_lowest(*dest))
			return (ps_lowindex(*dest));
	}
	return (0);
}

static int	__ps_dest_high(t_stack *dest, int val)
{
	size_t	iter;

	iter = -1;
	while (++iter < dest->cnt - 1)
	{
		if (val < dest->dat[iter])
		{
			if (val > dest->dat[iter + 1])
				return (iter + 1);
			else if (dest->dat[iter + 1] == ps_highest(*dest))
				return (iter + 1);
		}
		else if (val > ps_highest(*dest))
			return (ps_highindex(*dest));
	}
	return (0);
}
