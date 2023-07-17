#include<stdio.h>
#include<ctype.h>

void detailPrint(char ch)
{
    printf("\nPrinting the details of the character...\n\n");
    if(isdigit(ch))
    {
        printf("It is a number.\n");
    }
    else
    {
        int n = (int)ch;
        if(n >=65 && n<=90 || n >= 97 && n <= 122)
        {
            if(n >=65 && n<=90)
            {
                if(n == 65 || n == 69 || n == 73 || n == 79 || n == 85)
                {
                    printf("It is an uppercase vowel letter of alphabet.\n");
                    printf("It's ASCII value is %d.\n", n);
                }
                else
                {
                    printf("It is an uppercase consunant letter of alphabet.\n");
                    printf("It's ASCII value is %d.\n", n);
                }
            }
            else if(n >= 97 && n <= 122)
            {
                if(n == 97 || n == 101 || n == 105 || n == 111 || n == 117)
                {
                    printf("It is a lowercase vowel letter of alphabet.\n");
                    printf("It's ASCII value is %d.\n", n);
                }
                else
                {
                    printf("It is a lowercase consunant letter of alphabet.\n");
                    printf("It's ASCII value is %d.\n", n);
                }
            }
        }
        else
        {
            printf("It is a special character.\n");
            printf("It's ASCII value is %d.\n", n);
        }
    }
}

int main()
{
    char character;
    printf("Enter a character: ");
    scanf("%c", &character);
    detailPrint(character);
    return 0;
}