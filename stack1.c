/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:05:17 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/23 11:55:08 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	__ps_repetetive(t_stack *s, char *nptr);
static int	__ps_limitcross(char *nptr);

int	ps_validate(t_stack *s, char *av)
{
	return (
		ft_isnumer(av)
		&& !__ps_limitcross(av)
		&& !__ps_repetetive(s, av)
	);
}

static int	__ps_repetetive(t_stack *s, char *nptr)
{
	size_t	i;
	int		v;

	v = ft_atoi(nptr);
	i = -1;
	while (++i < s->cnt)
	{
		if (s->dat[i] == v)
			return (1);
	}
	return (0);
}

static int	__ps_limitcross(char *nptr)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r'
	)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr - '0');
		nptr++;
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (1);
	return (0);
}
