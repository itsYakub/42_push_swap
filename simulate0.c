/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:49:36 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/22 11:54:12 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	__ps_check_lowest(int *lowest, t_stack *s0, t_stack *s1, int *op);
static int	__ps_oper_mod(t_oper *oper, int op0, int op1);

int	ps_sim(t_stack *s0, t_stack *s1, t_oper *oper, char mod)
{
	int		lowest;
	int		op[2];
	size_t	iter;

	op[0] = 0;
	op[1] = 0;
	lowest = INT_MAX;
	iter = -1;
	while (++iter < s0->cnt)
	{
		op[0] = iter;
		if (mod == 'b')
			op[1] = ps_dest_in_stack(s1, s0->dat[iter], mod);
		else if (mod == 'a')
			op[1] = ps_dest_in_stack(s1, s0->dat[iter], mod);
		if (__ps_check_lowest(&lowest, s0, s1, op))
		{
			if (mod == 'b')
				__ps_oper_mod(oper, op[0], op[1]);
			else if (mod == 'a')
				__ps_oper_mod(oper, op[1], op[0]);
		}
	}
	return (1);
}

static int	__ps_check_lowest(int *lowest, t_stack *s0, t_stack *s1, int *op)
{
	if (*lowest > op[0] + op[1])
	{
		*lowest = op[0] + op[1];
		return (1);
	}
	else if (*lowest > ((int) s0->cnt - op[0]) + op[1])
	{
		*lowest = ((int) s0->cnt - op[0]) + op[1];
		return (1);
	}
	else if (*lowest > op[0] + ((int) s1->cnt - op[1]))
	{
		*lowest = op[0] + ((int) s1->cnt - op[1]);
		return (1);
	}
	else if (*lowest > ((int) s0->cnt - op[0]) + ((int) s1->cnt - op[1]))
	{
		*lowest = ((int) s0->cnt - op[0]) + ((int) s1->cnt - op[1]);
		return (1);
	}
	return (0);
}

static int	__ps_oper_mod(t_oper *oper, int op0, int op1)
{
	oper->ras = op0;
	oper->rbs = op1;
	return (1);
}
