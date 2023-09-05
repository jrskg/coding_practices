#include<stdio.h>
#define pi 3.14
int main(){
    double r1,r2,ac1,ac2;
    printf("radius of circle1 : ");
    scanf("%lf",&r1);
    printf("radius of circle2 : ");
    scanf("%lf",&r2);
    ac1=pi*r1*r1;
    ac2=pi*r1*r2;
    double area=ac1-ac2;
    printf("area of circle1 = %.2lf\n",ac1);
    printf("area of circle2 = %.2lf\n",ac2);
    printf("area of concentric circle = %.2lf\n",area);

    return 0;
}