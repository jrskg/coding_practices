#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node*TraversalFrwd(struct node* head)
{
    printf("The elements are shown below:\n");
    while(head != NULL)
    {
        printf("Elements:%d\n", head->data);
        head = head->next;
    }
}

struct node*TraversalBcwd(struct node* head)
{
    printf("The elements are shown below:\n");
    while(head->next != NULL)
    {
        head = head->next;
    }
    
    do 
    {
        printf("Elements:%d\n",head->data);
        head = head->prev;
        
    }while(head->prev != NULL);
   
    
}


int main()
{
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;
    struct node* fifth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
   // fifth = (struct node*)malloc(sizeof(struct node));
    
    head->prev = NULL;
    head->data = 2;
    head->next = second;
    
    second->prev = head;
    second->data = 4;
    second->next = third;
    
    third->prev = second;
    third->data = 6;
    third->next = fourth;
    
    fourth->prev = third;
    fourth->data = 8;
    fourth->next = NULL;
    
    TraversalFrwd(head);
    TraversalBcwd(head);
    return 0;
}
    