/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:46:57 by halwahed          #+#    #+#             */
/*   Updated: 2022/03/22 13:55:36 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* this function is for pushing  operations between stacks, pa & pb */

void	push_ab(t_stk **a, t_stk **b, t_stk *temp)
{
	temp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stk *)malloc(sizeof(t_stk));
		(*b)->prev = NULL;
		(*b)->num = (*a)->num;
		(*b)->next = NULL;
		(*a) = (*a)->next;
		(*a)->prev = NULL;
	}
	else
	{
		if (*a)
		{
			temp = (t_stk *)malloc(sizeof(t_stk));
			temp->num = (*a)->num;
			temp->next = NULL;
			temp->prev = NULL;
			add_front(b, temp);
			(*a) = (*a)->next;
		}
	}
}	
