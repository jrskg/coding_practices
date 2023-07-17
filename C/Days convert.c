#include <stdio.h>

int main() 
{ 
  int inputdays, years, months, weeks, days;
  printf("Enter the no. of days:\n");
  scanf("%d",&inputdays);
  
  years = inputdays / 365;
  inputdays = inputdays - (years * 365);
  months = inputdays / 30;
  inputdays = inputdays - (months * 30);
  weeks = inputdays / 7;
  days = inputdays - (weeks * 7);
  
  printf("%d YEARS\n",years);
  printf("%d MONTHS\n",months);
  printf("%d WEEKS\n",weeks);
  printf("%d DAYS\n",days);


 return 0; 
}