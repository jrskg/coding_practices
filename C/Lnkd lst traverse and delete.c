#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node
{
    int data;
    struct node* next;
};

struct node*Traversal(struct node* head)
{
    printf("The elements are shown below:\n");
    while(head != NULL)
    {
        printf("Elements:%d\n", head->data);
        head = head->next;
    }
}

struct node* insertAtFirst(struct node *head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

struct node* insertAtEnd(struct node *head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct node* insertAtIndex(struct node *head, int data, int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    int i = 0;
    while(i != index -1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct node*deleteFirst(struct node* head)
{
    struct node* ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct node*deleteLast(struct node* head)
{
    struct node* p = head;
    struct node* q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

struct node*deleteAtIndex(struct node* head, int index)
{
    struct node* p = head;
    struct node* q = head->next;

    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct node*deleteGivenElement(struct node* head, int element)
{
    struct node* p = head;
    struct node* q = head->next;

    while(q->data != element && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == element)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Sorry this element doesn't exist.\n");
        return head;
    }
    printf("Deletion completed successfully\n");
    return head;
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
    fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;
    second->data = 6;
    second->next = third;
    third->data = 9;
    third->next = fourth;
    fourth->data = 13;
    fourth->next = fifth;
    fifth->data = 15;
    fifth->next = NULL;
    while(1)
    {
        int n;
        int data;
        int index;
        printf("\nWhat do you want to do ?\n1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\n");
        scanf("%d", &n);

        if(n==1)
        {
            int insrt;
            printf("Where do you want to insert ?\n");
            printf("1.At the begining.\n2.At the end.\n3.At a given index.\n");
            scanf("%d", &insrt);

            if(insrt==1)
            {
                printf("Enter the element you want to insert:\n");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                printf("Insertion completed successfully\n");
            }
            else if(insrt==2)
            {
                printf("Enter the element you want to insert:\n");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Insertion completed successfully\n");
            }
            else if(insrt==3)
            {
                printf("Enter the element you want to insert\nAnd a index where you want to insert:\n");
                scanf("%d %d", &data, &index);
                head = insertAtIndex(head, data, index);
                printf("Insertion completed successfully\n");
            }
            else
            {
                printf("\nSomething went wrong...\nPlease try again\n");
            }

        }
        else if(n==2)
        {
            int delt;
            printf("From where you want to delete ?\n");
            printf("1.Delete first element.\n2.Delete last element.\n3.Delete element at of given index.\n4.Delete the given element\n");
            scanf("%d", &delt);

            if(delt==1)
            {
                printf("Deleting your first element...\n");
                sleep(2);
                head = deleteFirst(head);
                printf("Deletion completed successfully\n");
            }
            else if(delt==2)
            {
                printf("Deleting your last element...\n");
                sleep(2);
                head = deleteLast(head);
                printf("Deletion completed successfully\n");
            }
            else if(delt==3)
            {
                printf("Enter the index:\n");
                scanf("%d", &index);
                printf("Deleting your element at index no.%d...\n", index);
                sleep(2);
                head = deleteAtIndex(head, index);
                printf("Deletion completed successfully\n");
            }
            else if(delt==4)
            {
                int element;
                printf("Enter the element you want to delete:\n");
                scanf("%d", &element);
                printf("Deleting your element %d...\n", element);
                sleep(2);
                head = deleteGivenElement(head, element);
            }
            else
            {
                printf("\nSomething went wrong...\nPlease try again\n");
            }
        }
        else if(n==3)
        {
            Traversal(head);
        }
        else if(n==4)
        {
            printf("\nBye bye see you soon.\n");
            break;
        }
        else
        {
            printf("\nSomething went wrong...\nPlease try again\n");
        }

    }
    return 0;
}
