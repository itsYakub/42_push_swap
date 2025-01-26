/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:07:23 by joleksia          #+#    #+#             */
/*   Updated: 2025/01/22 11:50:47 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

typedef struct s_stack
{
	int		*dat;
	size_t	cnt;
	size_t	siz;
}	t_stack;

typedef struct s_oper
{
	int	ras;
	int	rras;
	int	rbs;
	int	rrbs;
	int	rrs;
	int	rrrs;
}	t_oper;

/* ./push_swap.c */
int	push_swap(t_stack *a, t_stack *b);
int	ps_issorted(t_stack stack);

/* ./stack0.c ./stack1.c */
int	ps_stack(t_stack *stack, size_t len);
int	ps_fill(t_stack *stack, char **av);
int	ps_validate(t_stack *s, char *av);
int	ps_free(t_stack *stack);

/* ./lang0.c ./lang1.c ./lang2.c ./lang3.c */
int	sa(t_stack *stack);
int	sb(t_stack *stack);
int	ss(t_stack *a, t_stack *b);
int	pa(t_stack *a, t_stack *b);
int	pb(t_stack *a, t_stack *b);
int	ra(t_stack *stack);
int	rb(t_stack *stack);
int	rr(t_stack *a, t_stack *b);
int	rra(t_stack *stack);
int	rrb(t_stack *stack);
int	rrr(t_stack *a, t_stack *b);

/* ./sort0.c ./sort1.c */
int	ps_sort3(t_stack *a);
int	ps_sort_atob(t_stack *a, t_stack *b);
int	ps_sort_btoa(t_stack *a, t_stack *b);
int	ps_dest_in_stack(t_stack *dest, int val, char mod);

/* ./utils.c */
int	ps_lowest(t_stack stack);
int	ps_highest(t_stack stack);
int	ps_lowindex(t_stack stack);
int	ps_highindex(t_stack stack);

/* ./simulate0.c */
int	ps_sim(t_stack *s0, t_stack *s1, t_oper *oper, char mod);
int	ps_simplify_opers(t_oper *oper);

#endif
