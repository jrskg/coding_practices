#include <stdio.h>

int main()
{
    int ptvNum = 0, n, negNum = 0;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i]>0) {
            ptvNum++;
        }
        else {
            negNum++;
        }
    }
    printf("The positive numbers are %d\n",ptvNum);
    printf("The negative numbers are %d\n",negNum);
    return 0;
}
