#include "monty.h"

/**
 * op_pop - remove the element at the top of the stack
 * @stack_p: stack pointer
 */
void op_pop(stack_t **stack_p)
{
	stack_t *top = NULL;

	if (!*stack_p)
		pfailure("L%u: can't pop an empty stack\n", op_env.lineno);

	if (*stack_p != (*stack_p)->prev)
	{
		top = (*stack_p)->prev;
		(*stack_p)->next->prev = top;
		top->next = (*stack_p)->next;
	}
	free(*stack_p);
	*stack_p = top;
}
