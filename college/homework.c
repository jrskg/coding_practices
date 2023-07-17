#include<stdio.h>
#include<stdlib.h>
#define PI 3.14

int main(){
    int choice;
    float length, breadth, radius;
    
    while(1){
        printf("Enter your choice.......\n\n1.Area of Rectangle\n2.Perimeter of Rectangle\n3.Area of Square\n4.Perimeter of Square\n5.Area of Triangle\n6.Area of Circle\n0.Press 0 to quit\n\n-------> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value of length and breadth : \n-------> ");
                scanf("%f%f", &length, &breadth);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Rectangle area = %.2f\n\n", length*breadth);
                break;
            case 2:
                printf("Enter the value of length and breadth : \n-------> ");
                scanf("%f%f", &length, &breadth);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Rectangle perimeter = %.2f\n\n", 2 * (length + breadth));
                break;
            case 3:
                printf("Enter the length of a side : \n-------> ");
                scanf("%f", &length);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Square area = %.2f\n\n", length * length);
                break;
            case 4:
                printf("Enter the length of a side : \n-------> ");
                scanf("%f", &length);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Square perimeter = %.2f\n\n", 4 * length);
                break;
            case 5:
                printf("Enter the value of length and breadth : \n-------> ");
                scanf("%f%f", &length, &breadth);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Triangle area = %.2f\n\n", (length * breadth)/2);
                break;
            case 6:
                printf("Enter the value of radius : \n-------> ");
                scanf("%f", &radius);
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Circle area = %.2f\n\n", PI * radius * radius);
                break;
            case 0:
                printf("THANKS FOR USING -> BYE BYE :)\n");
                exit(0);
            default:
                printf("\nInvalid input provided!!\n\n");
                break;
        }
    }

    return 0;
}