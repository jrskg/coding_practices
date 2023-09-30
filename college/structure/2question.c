#include <stdio.h>

struct employee{
    char name[20];
    char address[20];
    int age;
    float salary;
};

int main() {
    struct employee e[10];
    int size;
    float avgSalary = 0;
    printf("Enter number of employee : ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Employee %d\n", i+1);
        printf("Enter Employee Name : ");
        scanf("%s", e[i].name);
        printf("Enter Employee Address : ");
        scanf("%s", e[i].address);
        printf("Enter Age : ");
        scanf("%d", &e[i].age);
        printf("Enter Salary : ");
        scanf("%f", &e[i].salary);
    }

    printf("\nSN\t\tName\t\tAddress\t\tAge\t\tSalary\n");

    for(int i = 0; i < size; i++){
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%2.f\n", i+1, e[i].name, e[i].address, e[i].age, e[i].salary);
        avgSalary += e[i].salary;
    }

    avgSalary = avgSalary/size;

    printf("\nAverage salary : %.2f\n\n", avgSalary);
    
    return 0;
}