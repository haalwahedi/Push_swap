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
