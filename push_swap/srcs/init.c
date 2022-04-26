/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:06 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/22 15:02:07 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*ft_init_var(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->len = 0;
	v->line = NULL;
	v->split = NULL;
	v->print = 0;
	return (v);
}
