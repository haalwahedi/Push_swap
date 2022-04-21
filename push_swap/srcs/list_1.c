#include "push_swap.h"

/*
** The file has some list associated functions with generic purpose.
*/

/*
** this function is for freeing the stack when needed
*/
void	free_stk(t_stk **stk)
{
	t_stk	*temp;

	if (*stk)
	{
		while (*stk)
		{
			temp = (*stk)->next;
			free(*stk);
			*stk = NULL;
			(*stk) = temp;
		}
		free(*stk);
		*stk = NULL;
	}
}

/*
** this functuin finds the size of the list received in 'stk a'
*/
int	list_size(t_stk *a)
{
	int		len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

/*
** This function adds a 'new' item in the end of the stack
*/
void	add_back(t_stk **top, t_stk *new)
{
	t_stk	*temp;

	if (*top == NULL)
		*top = new;
	else
	{
		temp = *top;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

/*
**
*/
void	add_back_r(t_stk **top)
{
	t_stk	*temp1;
	t_stk	*temp2;

	temp1 = NULL;
	temp1 = *top;
	temp2 = (*top)->prev;
	while (temp1->next)
		temp1 = temp1->next;
	temp1->next = temp2;
	temp1->next->prev = temp1;
	temp1->next->next = NULL;
}

/*
** this function adds a 'new' number in the front of the stack
*/
void	add_front(t_stk **top, t_stk *new)
{
	new->next = (*top);
	new->prev = NULL;
	if ((*top) != NULL)
		(*top)->prev = new;
	(*top) = new;
}
