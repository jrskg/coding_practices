#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void enqueue();
void display();
int queue_array[MAX];
int i, rear = -1, front = -1, n;

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue(ENQUEUE) \n");
        // printf("2.Delete element from queue(DEQUEUE) \n");
        printf("2.Display all elements of queue \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("%d\n", rear);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }

    return 0;
}
void enqueue()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (front == -1){
            front = 0;
        }
            
        printf("Enter number of element to insert : ");
        scanf("%d", &n);
        if(rear + n > MAX){
            printf("Not possible\n");
            return;
        }
        printf("Enter all elements : ");
        
        for(i = rear+1; i <= (rear+n); i++){
            scanf("%d", &item);
            queue_array[i] = item;
        }
        rear += (n);
        
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Queue is : ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}