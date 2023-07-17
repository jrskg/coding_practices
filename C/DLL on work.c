#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head, * tail;

void Traversal()
{
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        printf("The elements are:\n");
        while(head != NULL)
        {
            printf("Element:%d\n", head->data);
            head = head->next;
        }
    }
}

void insertFirst(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        tail = newNode;
        head = newNode;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(int pos, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if(head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        tail = newNode;
        head = newNode;
    }
    else
    {
        int count = 0;
        Node* check = head;
        while(check != NULL)
        {
            count++;
            check = check->next;
        }
        if(pos == 1)
        {
            insertFirst(data);
        }
        else if(pos == count+1)
        {
            insertLast(data);
        }
        else if(pos > 1 && pos <= count)
        {
            Node* temp = head;
            int i = 1;
            while(i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        else
        {
            printf("Invalid position!\n\n");
        }
    }
}



int main()
{
    
    return 0;
}