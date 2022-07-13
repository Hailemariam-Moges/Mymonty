#include "monty.h"

/**
 * op_pint - print the value at the top of the stack
 * @stack_p: stack pointer
 */
void op_pint(stack_t **stack_p)
{
	if (*stack_p)
		printf("%d\n", (*stack_p)->n);
	else
		pfailure("L%u: can't pint, stack empty\n", op_env.lineno);
}
