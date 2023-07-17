#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    int marks;
    char fav_char;
    char name[30];
} arun, suraj, subodh;
//struct student arun, suraj, subodh;
void print()
{
    printf("%s\n",suraj.name);

}

int main()
{

    arun.roll = 5;
    arun.marks = 50;
    arun.fav_char = 'a';
    suraj.roll = 2;
    suraj.marks = 80;
    suraj.fav_char = 'm';
    subodh.roll = 3;
    subodh.marks = 70;
    subodh.fav_char = 's';
    strcpy(suraj.name,"MS SURAJ SKG");
    // printf("Roll no of arun is %d\n",arun.roll);
    // printf("arun got %d marks\n",arun.marks);
    // printf("favorite character of arun is %c\n",arun.fav_char);
    // printf("Roll no of suraj is %d\n",suraj.roll);
    // printf("suraj got %d marks\n",suraj.marks);
    // printf("favorite character of suraj is %c\n",suraj.fav_char);
    // printf("The name of suraj is %s\n",suraj.name);
    // printf("Roll no of subodh is %d\n",subodh.roll);
    // printf("subodh got %d marks\n",subodh.marks);
    // printf("favorite character of subodh is %c\n",subodh.fav_char);
    print();



    return 0;
}
