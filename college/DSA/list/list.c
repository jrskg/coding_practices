#include <stdio.h>
#include <stdlib.h>

struct list{
    int* arr;
    int size;
    int dataUpto;
};

typedef struct list list;

list* createList(int size){
    list* lst = (list*)malloc(sizeof(list));
    lst->arr = (int*)malloc(size * sizeof(int));
    lst->size = size;
    lst->dataUpto = -1;

    return lst;
}

int full(list* lst){
    return lst->dataUpto == lst->size - 1;
}

int empty(list* lst){
    return lst->dataUpto == -1;
}

void addToList(list* lst, int data, int index){
    if(full(lst)){
        printf("\n List is full\n");
        return;
    }

    for(int i = lst->dataUpto; i >= index; i--){
        lst->arr[i+1] = lst->arr[i];
    }
    lst->arr[index] = data;
    lst->dataUpto++;
}

void deleteByIndex(list* lst, int index){
    if(empty(lst)){
        printf("\n List is empty\n");
        return;
    }

    for(int i = index+1; i <= lst->dataUpto; i++){
        lst->arr[i-1] = lst->arr[i];
    }
    lst->dataUpto--;
}

void deleteByElement(list* lst, int elem){
    if(empty(lst)){
        printf("\nList is empty\n");
        return;
    }
    int idx = -1;
    for(int i = 0; i <= lst->dataUpto; i++){
        if(lst->arr[i] == elem){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        printf("\nGiven data do not exists\n");
        return;
    }
    deleteByIndex(lst, idx);
}

void traverse(list* lst){
    printf("\nThe list is --> ");
    for(int i = 0; i <= lst->dataUpto; i++){
        printf("%d ", lst->arr[i]);
    }
    printf("\n");
}

list* mergeList(list* l1, list* l2){
    if(empty(l1) && empty(l2)){
        printf("\nBoth list are empty\n");
        return NULL;
    }
    int newSize = l1->size + l2->size;
    int* newArr = (int*)malloc(newSize * sizeof(int));
    int k = 0;

    for(int i = 0; i <= l1->dataUpto; i++){
        newArr[k++] = l1->arr[i];
    }

    for(int i = 0; i <= l2->dataUpto; i++){
        newArr[k++] = l2->arr[i];
    }

    list* newList = (list*)malloc(sizeof(list));
    newList->arr = newArr;
    newList->size = newSize;
    newList->dataUpto = k-1;

    return newList;
}

int main() {
    int size, choice, data, index;
    printf("Enter size : ");
    scanf("%d", &size);

    list* lst = createList(size);

    while(choice != 7){
        printf("\n1.Insert\n2.Delete by index\n3.Delete by data\n4.Check full\n5.Check empty\n6.Print List\n7.Exit\n\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert : ");
                scanf("%d", &data);
                printf("Enter index to insert : ");
                scanf("%d", &index);
                addToList(lst, data,index);
                printf("\nData Insertion Success\n\n");
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteByIndex(lst, index);
                printf("\nDeletion Success\n\n");
                break;
            case 3:
                printf("Enter data to delete : ");
                scanf("%d", &data);
                deleteByElement(lst, data);
                printf("\nDeletion Success\n\n");
                break;
            case 4:
                if(full(lst)){
                    printf("\nList is full\n\n");
                }else{
                    printf("\nList is not full\n\n");
                }
                break;
            case 5:
                if(empty(lst)){
                    printf("\nList is empty\n\n");
                }else{
                    printf("\nList is not empty\n\n");
                }
                break;
            case 6:
                traverse(lst);
                break;
            case 7:
                printf("\nThanks for using\n\n");
                break;
            default:
                printf("\nInvalid input\n\n");
        }
    }
    
    return 0;
}