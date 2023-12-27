#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter a number : ");
    scanf("%d", &size);

    int * ptr = (int*)malloc(size * sizeof(int));
    printf("Enter all the elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &ptr[i]);
    }

    printf("The Array : ");
    for(int i = 0; i < size; i++){
        printf(" %d ", ptr[i]);
    }
    printf("\n");
    return 0;
}