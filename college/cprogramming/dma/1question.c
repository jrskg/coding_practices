#include <stdio.h>
#include <stdlib.h>

void printArray(int* p, int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", *(p+i));
    }
    printf("\n");
}

int main() {
    int *p = NULL, size;
    printf("Enter size : ");
    scanf("%d", &size);
    p = (int *)malloc(size * sizeof(int));

    printf("Enter %d numbers : ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", p+i);
    }

    for(int i = 0; i < size; i++){
        if(p[i] % 2 == 0){
            p[i] = 0;
        }else{
            p[i] = 1;
        }
    }

    printArray(p, size);
    free(p);
    return 0;
}