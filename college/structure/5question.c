#include <stdio.h>

struct student{
    char name[20];
    int roll;
    int mark[3];
    int total;
    float avg;
};

void printStudentDetails(struct student s[], int size){
    if(size == 0){
        printf("No student available currently\n");
        return;
    }

    printf("\nStudents details are\n");
    for(int i = 0; i < size; i++){
        printf("%d. %s\t%d\t", i+1, s[i].name, s[i].roll);
        for(int j = 0; j < 3; j++){
            printf("%d, ",s[i].mark[j]);
        }
        printf("  %d", s[i].total);
        printf("  %.2f\n", s[i].avg);
    }
}

void printGreaterAvg(struct student s[], int size){
    if(size == 0){
        printf("No student available currently\n");
        return;
    }
    int count = 0;
    printf("\nStudents details whose average is greater than 80 are\n");
    for(int i = 0; i < size; i++){
        if(s[i].avg > 80){
            printf("%d. %s\t%d\t", count+1, s[i].name, s[i].roll);
            for(int j = 0; j < 3; j++){
                printf("%d, ",s[i].mark[j]);
            }
            printf("  %d", s[i].total);
            printf("  %.2f\n", s[i].avg);
            count++;
        }
    }
    if(count == 0){
        printf("No user with average marks greater than 80\n");
    }
}

int main(){
    int size;
    struct student s[10];
    printf("Enter total number of students : ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        int total = 0, avg;
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
        s[i].total = total;
        avg = total/3;
        s[i].avg = avg;
    }
    printStudentDetails(s, size);
    printGreaterAvg(s, size);

    return 0;
}