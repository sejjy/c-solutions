// Modify Programming Project 6 from Chapter 10 so that it uses the stack ADT
// described in Section 19.4. You may use any of the implementations of the ADT
// described in that section.

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
	Stack s = create();
	char ch;
	int op1, op2;

	for (;;) {
		printf("Enter an RPN expression: ");

		for (;;) {
			scanf(" %c", &ch);

			if (ch >= '0' && ch <= '9')
				push(s, ch - '0');
			else if (ch == '+') {
				op2 = pop(s);
				op1 = pop(s);
				push(s, op1 + op2);
			} else if (ch == '-') {
				op2 = pop(s);
				op1 = pop(s);
				push(s, op1 - op2);
			} else if (ch == '*') {
				op2 = pop(s);
				op1 = pop(s);
				push(s, op1 * op2);
			} else if (ch == '/') {
				op2 = pop(s);
				op1 = pop(s);
				push(s, op1 / op2);
			} else if (ch == '=') {
				printf("Value of expression: %d\n", pop(s));
				make_empty(s);
				break;
			} else
				exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
