#include <stdio.h>
#include <stdlib.h>

struct queue{
    int *arr;
    int size;
    int front;
    int rear;
};
typedef struct queue Queue;

Queue* initQueue(int size){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->size = size;
    q->front = 0;
    q->rear = 0;
}

int empty(Queue* q){
    return q->rear == q->front;
}

int full(Queue* q){
    return q->rear == q->size;
}

void enqueue(Queue* q, int data){
    if(full(q)){
        printf("Queue is full\n");
        return;
    }

    q->arr[q->rear] = data;
    q->rear++;
}

int dequeue(Queue* q){
    if(empty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->arr[q->front];
    q->arr[q->front] = -1;
    q->front++;

    if(q->front == q->rear){
        q->front = 0;
        q->rear = 0;
    }

    return data;
}

int front(Queue* q){
    if(empty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}

void printQueue(Queue* q){
    printf("\n\n");
    for(int i = q->front; i < q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n\n");
}

int main() {
    int size, choice, data;
    printf("Enter size : ");
    scanf("%d", &size);

    Queue* q = initQueue(size);

    while(choice != 7){
        printf("\n1.Enqueue\n2.Dequeue\n3.Check full\n4.Check empty\n5.See front\n6.Print queue\n7.Exit\n\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                enqueue(q, data);
                printf("\nEnqueue Success\n\n");
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