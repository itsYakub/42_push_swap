/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:30:05 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/15 11:40:13 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumer(const char *s)
{
	int	signc;

	signc = 1;
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			if (*s == '-' && signc)
				signc--;
			else
				return (0);
		}
		s++;
	}
	return (1);
}
