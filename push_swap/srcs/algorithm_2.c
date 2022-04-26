/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:01:55 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 15:01:56 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The algorithm uses one pivot (pvt) as reference for the operations
** The 'check_pivot' in this case is responsible for findinf if the number at
** the top of the stack 'a' is lower or equals the pivot found;
** The pivot in this case will be the higher value of the chunck;
**
** if it meets the condition it will push the top number to the stack 'b'
** else the number will rotate of within stack 'a'
*/
void	first_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		pvt;
	t_stk	*temp1;
	t_stk	*temp2;

	i = len;
	while (i >= ft_abs(len / 4))
	{
		temp1 = ft_lst_dup(*a);
		pvt = get_pivot(temp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->num <= pvt)
			{
				temp2 = *a;
				pick_case(a, b, PB, v);
				i--;
				free(temp2);
			}
			else
				normalize_a(a, b, v, pvt);
		}
		free_stk(&temp1);
	}
}

/*
** then unsorted big numbers remains in stack 'a'
** The algorithm will pick the biggest number and send it to stack 'b'
** otherwise it will smart rotate the stack;
**
** This operation will continue while the list has numbers;
*/
void	second_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		min;
	t_stk	*temp;

	temp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		temp = (*a)->next;
		while ((*a)->num != min && temp && temp->num == min)
			pick_case(a, b, SA, v);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->num == min)
			{
				temp = *a;
				pick_case(a, b, PB, v);
				free(temp);
				len--;
			}
			else
				normalize_a(a, b, v, min);
		}
	}
}

/*
** Thist part is responsible for returning the numbers in the correct
** order.
** The pivot (max) is set to be the higher number in the stack 'b';
**
** While the pivot and the top of stack 'b' is equals
** it pushes the number to top of stack 'a'. 
** Otherwise, it will smart rotate the stack 'b' until the top number
** is the same as the pivot, when it will be sent to the top of stack
** 'a' as well. After the operation, it will find the maximun number
** again to adapt to the ajusted stack.
**
** In the end, all stack 'b' will be arranged in the stack 'a'.
*/
void	third_sort(t_stk **a, t_stk **b, int max, t_var *v)
{
	t_stk	*temp;

	temp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = get_max(*b);
			temp = (*b)->next;
			while ((*b)->num != max && temp && temp->num == max)
				pick_case(a, b, SB, v);
			while (((*b)->num != max) && *b)
				normalize_b(a, b, v, max);
			while (*b && (*b)->num == max)
			{
				temp = *b;
				pick_case(a, b, PA, v);
				max = get_max(*b);
				free(temp);
			}
		}
	}
}

void	sort_long(t_stk **a, t_stk **b, int len, t_var *v)
{
	int	max;

	max = 0;
	first_sort(a, b, len, v);
	second_sort(a, b, len, v);
	third_sort(a, b, max, v);
	free_stk(a);
	free_stk(b);
}
