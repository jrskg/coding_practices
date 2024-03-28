#include <stdio.h>
#include <stdlib.h>

struct circularQueue{
    int *arr;
    int rear;
    int front;
    int size;
};

typedef struct circularQueue Cqueue;

Cqueue* initCqueue(int initialCapacity){
    Cqueue* queue = (Cqueue*)malloc(sizeof(Cqueue));
    queue->arr = (int *)malloc(initialCapacity * sizeof(int));
    queue->size = initialCapacity;
    queue->rear = -1;
    queue->front = -1;

    return queue;
}

int full(Cqueue* q){
    return ((q->front == 0 && q->rear == q->size - 1) || (q->rear == q->front - 1));
}

int empty(Cqueue* q){
    return q->front == -1;
}

void enqueue(Cqueue* q, int data){
    if(full(q)){
        printf("\nQueue is full\n\n");
        return;
    }

    if(empty(q)){
        q->front = q->rear = 0;
    }else if(q->rear == q->size - 1 && q->front != 0){
        q->rear = 0;
    }else{
        q->rear++;
    }

    q->arr[q->rear] = data;
    printf("\nEnqueue Success\n\n");
}

int dequeue(Cqueue* q){
    if(empty(q)){
        return -1;
    }

    int data = q->arr[q->front];
    q->arr[q->front] = -1;

    if(q->front == q->size - 1){
        q->front = 0;
    }else if (q->front == q->rear){
        q->front = q->rear = -1;
    }else{
        q->front++;
    }
    return data;
}

int front(Cqueue* q){
    if(empty(q)){
        printf("\nQueue is empty\n\n");
        return -1;
    }

    return q->arr[q->front];
}

void printQueue(Cqueue* q){
    printf("\n\n");
    if(empty(q)){
        printf("\nQueue is empty\n\n");
        return;
    }
    int f = q->front;
    int r = q->rear;
    while(f != r){
        printf("%d ", q->arr[f]);
        if(f == q->size-1){
            f = 0;
        }else{
            f++;
        }
    }
    printf("%d", q->arr[f]);
    printf("\n\n");
}

int main() {
    int size, choice, data;
    printf("Enter size : ");
    scanf("%d", &size);

    Cqueue* q = initCqueue(size);

    while(choice != 7){
        printf("\n1.Enqueue\n2.Dequeue\n3.Check full\n4.Check empty\n5.See front\n6.Print queue\n7.Exit\n\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                int elem = dequeue(q);
                if(elem != -1){
                    printf("\nThe data is %d\n\n", elem);
                }
                break;
            case 3:
                if(full(q)){
                    printf("\nQueue is full\n\n");
                }else{
                    printf("\nQueue is not full\n\n");
                }
                break;
            case 4:
                if(empty(q)){
                    printf("\nQueue is empty\n\n");
                }else{
                    printf("\nQueue is not empty\n\n");
                }
                break;
            case 5:
                int frontElem = front(q);
                if(elem != -1){
                    printf("\nThe front element is %d\n\n", frontElem);
                }
                break;
            case 6:
                printQueue(q);
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