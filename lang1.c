/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lang1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:07:28 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/19 10:14:28 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	__ps_rotate(int	*arr, size_t siz);
static int	__ps_rrotate(int	*arr, size_t siz);

int	pa(t_stack *a, t_stack *b)
{
	if (!b->cnt)
		return (0);
	a->dat[a->cnt++] = b->dat[0];
	__ps_rrotate(a->dat, a->cnt);
	__ps_rotate(b->dat, b->cnt);
	b->cnt--;
	ft_putendl_fd("pa", STDOUT_FILENO);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (!a->cnt)
		return (0);
	b->dat[b->cnt++] = a->dat[0];
	__ps_rotate(a->dat, a->cnt);
	__ps_rrotate(b->dat, b->cnt);
	a->cnt--;
	ft_putendl_fd("pb", STDOUT_FILENO);
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

static int	__ps_rrotate(int	*arr, size_t siz)
{
	int		tmp;

	tmp = arr[siz - 1];
	while (siz-- > 1)
		arr[siz] = arr[siz - 1];
	arr[0] = tmp;
	return (1);
}
