// Modify Programming Project 1 from Chapter 10 so that it uses the stack ADT
// described in Section 19.4. You may use any of the implementations of the ADT
// described in that section.

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include "stackADT.h"

int main(void)
{
	Stack s = create();
	int ch;
	int opening_ch;
	bool nested_properly = true;

	printf("Enter parentheses and/or braces: ");
	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case '(':
			case '{':
				push(s, ch);
				break;
			case ')':
				opening_ch = pop(s);
				if (opening_ch != '(')
					nested_properly = false;
				break;
			case '}':
				opening_ch = pop(s);
				if (opening_ch != '{')
					nested_properly = false;
				break;
		}
	}

	if (!is_empty(s))
		nested_properly = false;

	printf("Parentheses/braces are ");
	if (!nested_properly) {
		printf("NOT nested properly\n");
		return 1;
	} else {
		printf("nested properly\n");
		return 0;
	}
}
