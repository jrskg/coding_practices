#include <stdio.h>

int main() {
    int n;
    char str[10];
    printf("Enter max number : ");
    scanf("%d", &n);

    FILE* numPtr = NULL;
    FILE* oddPtr = NULL;
    FILE* evenPtr = NULL;

    numPtr = fopen("./number.txt", "w");
    oddPtr = fopen("./odd.txt", "w");
    evenPtr = fopen("./even.txt", "w");

    fputc('-', numPtr);
    fputc('-', oddPtr);
    fputc('-', evenPtr);
    fclose(numPtr);
    fclose(oddPtr);
    fclose(evenPtr);

    numPtr = fopen("./number.txt", "a");
    oddPtr = fopen("./odd.txt", "a");
    evenPtr = fopen("./even.txt", "a");

    for(int i = 0; i <= n; i++){
        sprintf(str, "%d", i);
        fputs(str, numPtr);
        fputs(" ", numPtr);
        if(i % 2 == 0){
            fputs(str, evenPtr);
            fputs(" ", evenPtr);
        }else{
            fputs(str, oddPtr);
            fputs(" ", oddPtr);
        }
    }

    fclose(numPtr);
    fclose(oddPtr);
    fclose(evenPtr);
    return 0;
}