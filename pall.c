#include "monty.h"

/**
 * op_pall - print each element on the stack
 * @stack_p: stack pointer
 */
void op_pall(stack_t **stack_p)
{
	stack_t *p = NULL;

	if (*stack_p)
	{
		(*stack_p)->next->prev = NULL;

		for (p = *stack_p; p; p = p->prev)
			printf("%d\n", p->n);

		(*stack_p)->next->prev = *stack_p;
	}
}
