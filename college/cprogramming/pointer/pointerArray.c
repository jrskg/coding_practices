#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size : ");
    scanf("%d", &n);

    int * arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d numbers : ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }

    printf("The array is \n");
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
    return 0;
}