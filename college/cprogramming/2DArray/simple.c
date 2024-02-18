#include <stdio.h>
void printMat(int [3][3], int, int);

int main() {
    int arr[3][3], k = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = k++;
        }
    }
    printf("\nThe matrix is\n\n");
    printMat(arr, 3, 3);
    return 0;
}

void printMat(int arr[3][3], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}