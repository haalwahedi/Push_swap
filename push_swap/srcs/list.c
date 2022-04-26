/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:18 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/26 10:14:41 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*fill_list(t_var *v, char **split, t_stk *temp)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		temp = malloc(sizeof(t_stk));
		if (temp == NULL)
			return (NULL);
		temp->num = ps_atoll(split[i]);
		if (temp->num > 2147483647 || temp->num < -2147483648)
			ft_exit("ERROR\n", 1);
		temp->next = NULL;
		temp->prev = NULL;
		add_back(&v->a, temp);
		temp = NULL;
	}
	return (v->a);
}
