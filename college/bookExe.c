#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main() {
    float radius;
    int choice, num1, sum, num2;

    while(1){
        printf("\n1.Find area of cirlce\n2.Check odd or even\n3.Find sum upto n\n4.Exit\n-----> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value of radius : ");
                scanf("%f", &radius);
                printf("The area is %.2f\n", PI * radius * radius);
                break;

            case 2:
                printf("Enter a number to check : ");
                scanf("%d", &num1);
                if(num1 & 2)
                    printf("%d is odd\n", num1);
                else
                    printf("%d is even\n", num1);
                break;
            case 3:
                sum = 0;
                printf("Enter a number to sum : ");
                scanf("%d", &num2);
                for(int i = 0; i <= num2; i++){
                    sum += i;
                }
                printf("The sum upto %d is %d\n", num2, sum);
                break;
            case 4:
                printf("THANKS FOR USING BYE :)\n");
                exit(0);
            default:
                printf("Invalid input try again\n");
                break;
        }
    }
    return 0;
}