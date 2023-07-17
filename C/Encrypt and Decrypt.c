#include <stdio.h>

void encrypt(char st[])
{
    char *c = st;
    while(*c != '\0')
    {
        *c = *c + 3;
        *c++;
    }
}

void decrypt(char st[])
{
    char *c = st;
    while(*c != '\0')
    {
        *c = *c - 3;
        *c++;
    }
}

int main()
{   int n;
    char input;

    printf("Enter the lenght of your message\n");
    scanf("%d",&n);
    char str[n];


    printf("Press E to encrypt and D to decrypt\n");
    scanf(" %c",&input);

    switch(input)
    {
    case'E':
            getchar();
        printf("Enter your message\n");
        gets(str);
        encrypt(str);
        printf("Your encrypted message is:\n%s", str);
        break;

    case'D':
            getchar();
        printf("Enter your message\n");
        gets(str);
        decrypt(str);
        printf("Your decrypted message is:\n%s", str);
        break;

    default:
        printf("Invalid input!");
        break;
    }
    return 0;
}
    