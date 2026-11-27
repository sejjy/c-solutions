#include <stdio.h>

int main(void)
{
	int amount;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	int count = amount / 20;

	printf("\n$20 bills: %d\n", count);

	amount = amount - (count * 20);
	count = amount / 10;

	printf("$10 bills: %d\n", count);

	amount = amount - (count * 10);
	count = amount / 5;

	printf(" $5 bills: %d\n", count);

	amount = amount - (count * 5);
	count = amount / 1;

	printf(" $1 bills: %d\n", count);

	return 0;
}
