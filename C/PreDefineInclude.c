#include <stdio.h>
#define PI 3.14
#define SQUARE(r) r*r
 
int main()
{
	 float radius, area;
  printf("Enter the radius of the circle in cm:\n");
  scanf("%f",&radius);
  area = PI * SQUARE(radius);
  printf("The area is %.2f cm2\n",area);

	return 0;
}
 