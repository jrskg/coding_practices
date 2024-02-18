#include <stdio.h>

struct student{
    char name[20];
    int roll;
    float marks;
    char remarks;
};

int main() {
    struct student s[10];
    int size;
    printf("Enter number of students : ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Student %d\n", i+1);
        printf("Enter name : ");
        scanf("%s", s[i].name);
        printf("Enter roll number : ");
        scanf("%d", &s[i].roll);
        printf("Enter marks : ");
        scanf("%f", &s[i].marks);
        printf("Enter remarks : ");
        getchar();
        scanf("%c", &s[i].remarks);
    }

    printf("SN\t\tName\t\tRoll Number\t\tMarks\t\tRemarks\n");

    for(int i = 0; i < size; i++){
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%c\n", i+1, s[i].name, s[i].roll, s[i].marks, s[i].remarks);
    }
    
    return 0;
}