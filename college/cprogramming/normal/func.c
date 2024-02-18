#include <stdio.h>

void greater(){
    int a, b, n;
    printf("How many numbers you wanna check : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter number : ");
        scanf("%d", &a);
        if(a > b){
            b = a;
        }
    }
    printf("%d is greatest\n", b);
}

void area(){
    int l, b;
    printf("Enter length : ");
    scanf("%d", &l);
    printf("Enter breadth : ");
    scanf("%d", &b);
    printf("The area is %d\n", l*b);
}

void sortArray(int *arr, int size){
    int isSorted;
    for(int i = 0; i < size-1; i++){
        isSorted = 1;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            break;
        }
    }
}

void volume(){
    int l, b, h;
    printf("Enter length : ");
    scanf("%d", &l);
    printf("Enter breadth : ");
    scanf("%d", &b);
    printf("Enter height : ");
    scanf("%d", &h);
    printf("The volume is %d\n", l*b*h);
}

void printArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // greater();
    // area();
    // volume();
    // int arr[20], size;
    // printf("Enter size : ");
    // scanf("%d", &size);
    // printf("Enter %d numbers : ", size);
    // for(int i = 0; i < size; i++){
    //     scanf("%d", &arr[i]);
    // }
    // sortArray(arr, size);
    // printArray(arr, size);
    int n;
    n = printf("Helloo");
    printf("The return value is : %d\n", n);

    return 0;
}