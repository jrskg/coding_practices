#include <stdio.h>

union student{
    char name[20];
    int roll;
    float marks;
};

int main() {
    union student s;

    printf("Enter name : ");
    scanf("%s", s.name);
    printf("\nName is : %s\n\n", s.name);
    printf("Enter roll number : ");
    scanf("%d", &s.roll);
    printf("\nRoll number is : %d\n\n", s.roll);
    printf("Enter marks : ");
    scanf("%f", &s.marks);
    printf("\nMarks is : %.2f\n\n", s.marks);
    return 0;
}