#include<stdio.h>
#include<math.h>
#define PI 3.1415926536
#define SQUARE(s) s*s

float calculateArea(float r)
{
    float ar = PI * SQUARE(r);
    return ar;
}

float Edistance(int x1,int y1,int x2,int y2)
{
    float a = (x2 - x1)*(x2 - x1) + (y2 -y1)*(y2 -y1);
    return sqrt(a);
}

int main()
{
    int x1, y1, x2, y2;
    printf("Enter the value of x1:\n");
    scanf("%d",&x1);

    printf("Enter the value of y1:\n");
    scanf("%d",&y1);

    printf("Enter the value of x2:\n");
    scanf("%d",&x2);

    printf("Enter the value of y2:\n");
    scanf("%d",&y2);

    float dst = Edistance(x1, y1, x2, y2);
    printf("The distance is %.2f Unit\n",dst);

    float area = calculateArea(dst);
    printf("The area is %.2f Unit\n",area);
    return 0;
}