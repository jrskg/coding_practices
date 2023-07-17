#include <stdio.h>

void printstr(char str[])
{ 
  int i = 0;
  while(str[i]!='\0')
   {
      printf("%c",str[i]);
      i++;
     
  }
  
   printf("\n");


}

int main()
{
  char str[35];
  printf("Enter your sentences\n");
  gets(str);
  printf("Using printf %s\n",str);
  printf("Using puts\n");
  puts(str);
  printf("Using function\n");
  printstr(str);
  
 return 0;

}