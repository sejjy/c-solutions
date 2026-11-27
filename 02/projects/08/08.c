#include <stdio.h>

#define MONTHS_IN_YEAR 12

int main(void)
{
	float loan, interest_rate, monthly_payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	// loan = 20000.0f;
	// interest_rate = 6.0f;
	// monthly_payment = 386.66f;

	float percentage = interest_rate / 100;

	loan = (loan - monthly_payment) + (loan * (percentage / MONTHS_IN_YEAR));

	printf("\nBalance remaining after first payment: %.2f\n", loan);

	loan = (loan - monthly_payment) + (loan * (percentage / MONTHS_IN_YEAR));

	printf("Balance remaining after second payment: %.2f\n", loan);

	loan = (loan - monthly_payment) + (loan * (percentage / MONTHS_IN_YEAR));

	printf("Balance remaining after third payment: %.2f\n", loan);

	return 0;
}
