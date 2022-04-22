/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:37:57 by halwahed          #+#    #+#             */
/*   Updated: 2022/03/22 13:56:15 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function deals with the swapping operations between 
 * stack A and B, sa & sb */

void	s_stk(t_stk **top)
{
	int		i;
	int		j;
	t_stk	*temp;

	temp = NULL;
	if ((*top) && (*top)->next)
	{
		temp = *top;
		i = (*top)->num;
		j = (*top)->next->num;
		temp = *top;
		(*top)->num = j;
		temp = *top;
		(*top)->next->num = i;
		(*top) = temp;
	}
}
