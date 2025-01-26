/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:47:43 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/22 08:46:46 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	__ps_process_rots(t_stack *a, t_stack *b, t_oper *oper);
static int	__ps_proces_rs(t_stack *a, t_stack *b, t_oper *oper);
static int	__ps_proces_rrs(t_stack *a, t_stack *b, t_oper *oper);

int	ps_sort_atob(t_stack *a, t_stack *b)
{
	size_t	index;
	t_oper	oper;

	pb(a, b);
	if (a->cnt <= 3)
		return (1);
	pb(a, b);
	while (a->cnt > 3)
	{
		oper = (t_oper){0};
		index = ps_sim(a, b, &oper, 'b');
		__ps_process_rots(a, b, &oper);
		pb(a, b);
	}
	return (1);
}

int	ps_sort_btoa(t_stack *a, t_stack *b)
{
	size_t	index;
	t_oper	oper;

	while (b->cnt)
	{
		oper = (t_oper){0};
		index = ps_sim(b, a, &oper, 'a');
		__ps_process_rots(a, b, &oper);
		pa(a, b);
	}
	while (a->dat[0] != ps_lowest(*a))
	{
		if (ps_lowindex(*a) > (int) a->siz / 2)
			rra(a);
		else
			ra(a);
	}
	return (1);
}

static int	__ps_process_rots(t_stack *a, t_stack *b, t_oper *oper)
{
	if (oper->ras > (int) a->cnt / 2)
	{
		oper->rras = a->cnt - oper->ras;
		oper->ras = 0;
	}
	if (oper->rbs > (int) b->cnt / 2)
	{
		oper->rrbs = b->cnt - oper->rbs;
		oper->rbs = 0;
	}
	__ps_proces_rs(a, b, oper);
	__ps_proces_rrs(a, b, oper);
	while (oper->ras-- > 0)
		ra(a);
	while (oper->rbs-- > 0)
		rb(b);
	while (oper->rras-- > 0)
		rra(a);
	while (oper->rrbs-- > 0)
		rrb(b);
	return (1);
}

static int	__ps_proces_rs(t_stack *a, t_stack *b, t_oper *oper)
{
	if (oper->ras > 0 && oper->rbs > 0)
	{
		if (oper->ras > oper->rbs)
		{
			oper->rrs = oper->rbs;
			oper->ras -= oper->rbs;
			oper->rbs = 0;
		}
		else
		{
			oper->rrs = oper->ras;
			oper->rbs -= oper->ras;
			oper->ras = 0;
		}
	}
	while (oper->rrs-- > 0)
		rr(a, b);
	return (0);
}

static int	__ps_proces_rrs(t_stack *a, t_stack *b, t_oper *oper)
{
	if (oper->rras > 0 && oper->rrbs > 0)
	{
		if (oper->rras > oper->rrbs)
		{
			oper->rrrs = oper->rrbs;
			oper->rras -= oper->rrbs;
			oper->rrbs = 0;
		}
		else
		{
			oper->rrrs = oper->rras;
			oper->rrbs -= oper->rras;
			oper->rras = 0;
		}
	}
	while (oper->rrrs-- > 0)
		rrr(a, b);
	return (0);
}
