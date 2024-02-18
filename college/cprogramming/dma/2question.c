#include <stdio.h>
#include <stdlib.h>

struct Programmer{
    char name[20];
    char role[20];
    char language[20];
    char pId[20];
    int salary;
    char joinedAt[20];
};

void takeInput(struct Programmer* p, int size){
    printf("Enter details of %d programmer\n", size);
    for(int i = 0; i < size; i++){
        printf("Enter name : ");
        scanf("%s", p[i].name);
        printf("Enter role : ");
        scanf("%s", p[i].role);
        printf("Enter salary : ");
        scanf("%d", &p[i].salary);
        printf("Enter language : ");
        scanf("%s", p[i].language);
        printf("Enter id : ");
        scanf("%s", p[i].pId);
        printf("Enter joining date (yyyy-mm-dd) : ");
        scanf("%s", p[i].joinedAt);
    }
}

void printDetails(struct Programmer* p, int size){
    printf("\n\nThe details of progranmers are given below\n\n");
    for(int i = 0; i < size; i++){
        printf("_PID -->\t%s\n", p[i].pId);
        printf("NAME -->\t%s\n", p[i].name);
        printf("ROLE -->\t%s\n", p[i].role);
        printf("LANGUAGE -->\t%s\n", p[i].language);
        printf("SALARY -->\t%d\n", p[i].salary);
        printf("JOINED AT -->\t%s\n\n", p[i].joinedAt);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the number of programmer : ");
    scanf("%d", &size);

    struct Programmer* p = (struct Programmer*)malloc(size * sizeof(struct Programmer));
    takeInput(p, size);
    printDetails(p, size);

    return 0;
}