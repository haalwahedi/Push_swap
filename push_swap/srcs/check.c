/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:02:01 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/26 10:43:39 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check_sort - will validate if the list is correctly populated;
*/
int	check_sort(t_stk **a, int len)
{
	t_stk	*temp;

	if (list_size(*a) != len)
		return (0);
	(void)len;
	temp = *a;
	while (temp && temp->next)
	{
		if ((temp)->next != NULL && ((temp)->num < (temp)->next->num))
			(temp) = temp->next;
		else
			return (0);
	}
	return (1);
}

/*
** Check_dup - check if there is any duplicated numbers within the list
*/
void	check_dup(char **av, t_var *v)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(dup, av[j]) == 0)
			{
				free(v);
				ft_free_arg(&dup);
				ft_exit("Error\n", 1);
			}
			else
				j++;
		}
		ft_free_arg(&dup);
		i++;
	}
}

/*
** This function will check if there is any overflow.
*/
int	check_overflow(char *arg)
{
	long long	temp;

	temp = ps_atoll(arg);
	if (temp >= INT_MIN && temp <= INT_MAX && ft_strlen(arg) < 12)
		return (1);
	return (0);
}

/*
** Check_numbers will validate if all arguments are numbers
*/
int	check_numbers(char **av, t_var *v)
{
	int		i;
	int		j;

	i = -1;
	if (!av[0])
		free_exit(v);
	while (av[++i])
	{
		j = -1;
		if (check_overflow(av[i]) == 0)
		{
			free_exit(v);
		}
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.'
			|| ((av[i][j]) == '-' && (av[i][j + 1]) == '\0')
			|| ((av[i][j]) == '+' && (av[i][j + 1]) == '\0'))
			{
				free_exit(v);
			}
		}
	}
	return (1);
}

/*
** Check_pivot - is responsible to find if flag is '1', related to the stack a
** where it is important to know if the number is lower or equals to the pivot
**
** If flag '2', you intend to check if the number is the pivot selected;
*/
int	check_pivot(t_stk *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->num <= pvt)
				return (1);
			a = a->next;
		}
		if (flag == 2)
		{
			if (a->num == pvt)
				return (1);
			a = a->next;
		}
	}
	return (0);
}
