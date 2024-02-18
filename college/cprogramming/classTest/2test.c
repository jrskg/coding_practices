#include <stdio.h>

int main() {
    int nums[5], temp;
    printf("Enter all five numbers : ");
    for (int i = 0; i < 5; i++){
        scanf("%d", &nums[i]);
    }

    printf("Array before sortong \n");
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4-i; j++){
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

    printf("\nArray after sortong \n");
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}