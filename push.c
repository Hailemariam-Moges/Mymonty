#include "monty.h"

/**
 * op_push - push an element onto the stack
 * @stack_p: stack pointer
 */
void op_push(stack_t **stack_p)
{
	stack_t *new = NULL;
	const char *nstr = op_env.argv[1];

	if (!(nstr && isinteger(nstr)))
		pfailure("L%u: usage: push integer\n", op_env.lineno);

	new = malloc(sizeof(*new));
	if (!new)
		pfailure("Error: malloc failed\n");

	new->n = atoi(nstr);
	if (*stack_p)
	{
		new->prev = (*stack_p);
		new->next = (*stack_p)->next;
		new->next->prev = new;
		(*stack_p)->next = new;
		if (op_env.mode == LIFO)
			(*stack_p) = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		(*stack_p) = new;
	}
}
