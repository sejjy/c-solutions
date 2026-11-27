#include <stdio.h>

#define VOLUME_FACTOR (4.0f / 3.0f)
#define PI 3.141592f

int main(void)
{
	printf("Sphere\n");
	printf("Radius = 10\n");
	printf("Volume = %.2f\n", VOLUME_FACTOR * PI * 10 * 10 * 10);

	return 0;
}
