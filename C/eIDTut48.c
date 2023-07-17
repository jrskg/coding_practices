#include <stdio.h>
#include <stdlib.h>
int main()
{
    char* name;
    int n,i = 0;
    while(i < 3)
    {
        printf("Employee %d.Enter the number of character in your employee id\n",i+1);
        scanf("%d",&n);
        name = (char*)malloc((n+1)*sizeof(char));
        printf("Enter the employee id\n");
        scanf("%s",name);
        printf("The id of employee %d is %s\n",i+1, name);
        i = i+1;
        free(name);
    }
    /*
        printf("Enter the number of character of your first employee id\n");
        scanf("%d",&n);
        name = (char*)malloc((n+1)*sizeof(char));
        printf("For the first employee\n");
        printf("Enter the first employee id\n");
        scanf("%s",name);
        printf("The id of 1st employee is %s\n",name);


        printf("Enter the number of character of your second employee id\n");
        scanf("%d",&n);
        name = (char*)realloc(name,(n+1)*sizeof(char));
        printf("For the second employee\n");
        printf("Enter the second employee id\n");
        scanf("%s",name);
        printf("The id of 2nd employee is %s\n",name);


        printf("Enter the number of character of your third employee id\n");
        scanf("%d",&n);
        name = (char*)realloc(name,(n+1)*sizeof(char));
        printf("For the third employee\n");
        printf("Enter the third employee id\n");
        scanf("%s",name);
        printf("The id of 3rd employee is %s\n",name);

     */
    return 0;
}
