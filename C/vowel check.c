#include <stdio.h>
 
int main()
{
	 char input;
  printf("Enter an alphabet to check:\n");
  scanf("%c",&input);
  
  if(input == 'a'|| input == 'e'|| input == 'i'|| input == 'o'|| input == 'u' || input == 'A'|| input == 'E'|| input == 'I'|| input == 'O'|| input == 'U')
   printf("%c is a vowel letter.\n",input);
  else if(input == 'w' || input == 'y' || input == 'W' || input == 'Y')
   printf("%c is a semi vowel letter.\n",input);
  else
   printf("%c is a consonant letter.\n",input);
	return 0;
}
 