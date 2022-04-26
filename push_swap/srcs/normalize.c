/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:23 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 15:10:22 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Theses functions were set to better choose how to
** rotate the stack 'a' and 'b' in the short sorting
*/
void	normalize_a(t_stk **a, t_stk **b, t_var *v, int pvt)
{
	int	index;
	int	num;

	index = get_idx((*a), pvt, 1);
	num = (list_size((*a)) / 2);
	if (index < num)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	normalize_b(t_stk **a, t_stk **b, t_var *v, int pvt)
{
	int	index;
	int	num;

	index = get_idx((*b), pvt, 2);
	num = ft_abs((list_size((*b)) / 2));
	if (index < num && *b)
		pick_case(a, b, RB, v);
	else if (*b)
		pick_case(a, b, RRB, v);
}
