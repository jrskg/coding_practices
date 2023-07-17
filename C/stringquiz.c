#include <stdio.h>
#include <string.h>


int main()
{
    char s1[15];
    char s2[15];
    char s3[20];

    printf("Enter the first name\n");
    gets(s1);

    printf("Enter the second name\n");
    gets(s2);

    printf("%s is a friend of %s\n",s1,s2);

   // puts(strcat(s1,s2));
    
    strcpy(s3,strcat(s1,s2));
    puts(s3);

    return 0;
}
