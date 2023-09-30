#include <stdio.h>

void printMat(int [10][10], int , int);
void transposeMat(int [10][10], int [10][10], int, int);

int main() {
    int arr[10][10], transpose[10][10], row, col;
    printf("Enter row (< 10) : ");
    scanf("%d", &row);
    printf("Enter column (< 10) : ");
    scanf("%d", &col);
    printf("Enter total %d element : ", row*col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nArray before transposing\n\n");
    printMat(arr, row, col);
    transposeMat(arr, transpose, row, col);
    printf("\nArray after transposing\n\n");
    printMat(transpose, row, col);
    return 0;
}

void printMat(int arr[10][10], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void transposeMat(int arr[10][10], int trans[10][10], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            trans[i][j] = arr[j][i];
        }
    }
}