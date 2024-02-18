#include <stdio.h>

struct student{
    char name[20];
    int roll;
    int mark[3];
    int totalMarks;
};

void printStudentDetails(struct student s[], int size){
    if(size == 0){
        printf("No student available currently\n");
        return;
    }

    printf("Students details are\n");
    for(int i = 0; i < size; i++){
        printf("%d. %s\t%d\t", i+1, s[i].name, s[i].roll);
        for(int j = 0; j < 3; j++){
            printf("%d, ",s[i].mark[j]);
        }
        printf("  %d\n", s[i].totalMarks);
    }
}

void sortAsc(struct student s[], int size){
    int isSorted;
    struct student temp;
    for(int i = 0; i < size-1; i++){
        isSorted = 0;
        for(int j = 0; j < size-1-i; j++){
            if(s[j].totalMarks > s[j+1].totalMarks){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
                isSorted = 1;
            }
        }
        if(isSorted == 0){
            break;
        }
    }
}

int main(){
    int size;
    struct student s[10];
    printf("Enter total number of students : ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        int total = 0;
        printf("Student %d\n", i+1);
        printf("Enter name : ");
        scanf("%s", s[i].name);
        printf("Enter roll : ");
        scanf("%d", &s[i].roll);
        printf("Enter marks of 3 subject : ");
        for(int j = 0; j < 3; j++){
            scanf("%d", &s[i].mark[j]);
            total += s[i].mark[j];
        }
        s[i].totalMarks = total;
    }

    printf("\nBefore sorting\n");
    printStudentDetails(s, size);
    sortAsc(s, size);
    printf("\nAfter sorting\n");
    printStudentDetails(s, size);

    return 0;
}