/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:28:51 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/22 11:48:35 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lowest(t_stack stack)
{
	size_t	iter;
	int		lowest;

	lowest = INT_MAX;
	iter = -1;
	while (++iter < stack.cnt)
	{
		if (stack.dat[iter] < lowest)
			lowest = stack.dat[iter];
	}
	return (lowest);
}

int	ps_highest(t_stack stack)
{
	size_t	iter;
	int		highest;

	highest = INT_MIN;
	iter = -1;
	while (++iter < stack.cnt)
	{
		if (stack.dat[iter] > highest)
			highest = stack.dat[iter];
	}
	return (highest);
}

int	ps_lowindex(t_stack stack)
{
	int	iter;

	iter = -1;
	while (++iter < (int) stack.cnt)
	{
		if (stack.dat[iter] == ps_lowest(stack))
			break ;
	}
	return (iter);
}

int	ps_highindex(t_stack stack)
{
	int	iter;

	iter = -1;
	while (++iter < (int) stack.cnt)
	{
		if (stack.dat[iter] == ps_highest(stack))
			break ;
	}
	return (iter);
}
