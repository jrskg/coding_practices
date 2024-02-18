#include <stdio.h>

int main() {
    FILE* fp;
    char c;
    fp = fopen("./okay.txt", "w");
    printf("Enter the characters until enter : ");
    while((c = getchar()) != '\n'){
        fputc(c, fp);
    }
    fclose(fp);

    fp = fopen("./okay.txt", "r");
    while(c != EOF){
        c = fgetc(fp);
        if(c != EOF){
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}