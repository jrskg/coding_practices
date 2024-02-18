#include <stdio.h>
void printArray(int [], int);
int arraySum(int [], int);

int main() {
    int arr[20], size;
    printf("Enter size : ");
    scanf("%d", &size);
    printf("Enter %d elements : ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printArray(arr, size);
    int sum = arraySum(arr, size);
    printf("The sum is %d\n", sum);
    return 0;
}

void printArray(int arr[], int size){
    printf("Array ----> ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int arraySum(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}