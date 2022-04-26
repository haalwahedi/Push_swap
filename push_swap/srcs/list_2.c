/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:12 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/26 10:18:38 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function will duplicate the list & return them as temp 1;
*/
t_stk	*ft_lst_dup(t_stk *stk)
{
	t_stk	*temp1;
	t_stk	*temp2;

	temp1 = malloc(sizeof(t_stk));
	ft_bzero(temp1, sizeof(t_stk));
	temp2 = temp1;
	while (stk)
	{
		temp1->num = stk->num;
		if (stk->next)
		{
			temp1->next = malloc(sizeof(t_stk));
			if (temp1 == NULL)
				ft_exit("Error\n", 1);
			ft_bzero(temp1->next, sizeof(t_stk));
			temp1 = temp1->next;
		}
		stk = stk->next;
	}
	temp1 = temp2;
	return (temp1);
}

/*
** this function finds the bottom number of the list
*/
t_stk	*ft_lst_bottom(t_stk *a)
{
	t_stk	*temp;

	temp = a;
	while ((temp)->next)
		(temp) = (temp)->next;
	return (temp);
}
