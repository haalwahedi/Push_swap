/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:03 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 15:02:04 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The index number is the parameter to rotate numbers in two cases
** case '1' will occur when the number you want to know the lower
** number in the stack, case '2' will occur when you want to set the maximun
** number to the index.
*/
int	get_idx(t_stk *stk, int num, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		while (stk)
		{
			if (stk->num <= num)
				return (i);
			stk = stk->next;
			i++;
		}
	}
	if (flag == 2)
	{
		while (stk)
		{
			if (stk->num >= num)
				return (i);
			stk = stk->next;
			i++;
		}
	}
	return (-1);
}

/*
** After some research and testing, there is a range of 
** efficiency when it comes to the size of the lists analyzed
** 
*/
int	get_pivot(t_stk *stk)
{
	t_stk	*temp;
	int		len;
	int		pvt;

	pvt = 0;
	len = 0;
	temp = NULL;
	len = list_size(stk);
	temp = ft_lstsort(stk);
	if (len <= 10)
		pvt = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pvt = ft_abs(len / 4);
	else if (len >= 200)
		pvt = ft_abs(len / 8);
	return (ft_lstnbr(&temp, pvt));
}

/*
** This function will find the maximum number in the stack.
*/
int	get_max(t_stk *stk)
{
	int		max;
	t_stk	*temp;

	max = 0;
	temp = NULL;
	if (stk)
	{
		max = stk->num;
		temp = stk;
		while (stk)
		{
			if (stk->num >= max)
				max = stk->num;
			stk = stk->next;
		}
		stk = temp;
	}
	return (max);
}

/*
** This function will find the minimum number in the stack.
*/
int	get_min(t_stk *stk)
{
	int	min;

	min = stk->num;
	while (stk)
	{
		if (stk->num < min)
			min = stk->num;
		stk = stk->next;
	}
	return (min);
}
