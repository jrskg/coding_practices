#include <stdio.h>

int main() {
    int choice, num, temp = 0, org;
    printf("\n1 for odd even check\n2 for multiplication table\n3 for palindrome check\n\nEnter choice : ");
    scanf("%d", &choice);
    printf("Enter a number : ");
    scanf("%d", &num);

    switch(choice){
        case 1:
            if(num % 2 == 0){
                printf("%d is even\n", num);
            }else{
                printf("%d is odd\n", num);
            }
            break;
        case 2:
            printf("The multiplication table is\n");
            for(int i = 1; i <= 10; i++){
                printf("%d x %d = %d\n", num, i, num*i);
            }
            break;
        case 3:
            org = num;
            while(num != 0){
                temp = (temp * 10) + (num % 10);
                num = num/10;
            }
            if(temp == org){
                printf("%d is palindrome\n", org);
            }else{
                printf("%d is not a palindrome\n", org);
            }
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    return 0;
}