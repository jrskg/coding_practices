#include <stdio.h>
int search(int [], int, int);

int main() {
    int arr[20], size, elem;
    printf("Enter size : ");
    scanf("%d", &size);
    printf("Enter %d elements : ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search : ");
    scanf("%d", &elem);
    int i = search(arr, size, elem);
    if(i < 0){
        printf("%d doesn't exist in the array\n", elem);
    }else{
        printf("%d found at %dth index of the array\n", elem, i);
    }
    return 0;
}

int search(int arr[], int size, int elem){
    for(int i = 0; i < size; i++){
        if(arr[i] == elem){
            return i;
        }
    }
    return -1;
}
