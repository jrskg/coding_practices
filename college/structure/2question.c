#include <stdio.h>
#include <stdlib.h>

struct employee{
    char name[20];
    char address[20];
    int age;
    float salary;
};

int main() {
    int n;
    float avgSalary = 0;
    printf("Enter number of employee : ");
    scanf("%d", &n);

    struct employee* e = (struct employee*)malloc(n * sizeof(struct employee));
    
    for(int i = 0; i < n; i++){
        printf("\nEnter information of Employee %d\n", i+1);
        
        scanf("%*c");
        printf("Enter Employee Name : ");
        scanf("%[^\n]", e[i].name);

        scanf("%*c");
        printf("Enter Employee Address : ");
        scanf("%[^\n]", e[i].address);

        printf("Enter Age : ");
        scanf("%d", &e[i].age);

        printf("Enter Salary : ");
        scanf("%f", &e[i].salary);
    }

    printf("\nSN\t\tName\t\tAddress\t\tAge\t\tSalary\n");

    for(int i = 0; i < n; i++){
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%2.f\n", i+1, e[i].name, e[i].address, e[i].age, e[i].salary);
        avgSalary += e[i].salary;
    }

    avgSalary = avgSalary/n;

    printf("\nAverage salary : %.2f\n\n", avgSalary);
    
    return 0;
}