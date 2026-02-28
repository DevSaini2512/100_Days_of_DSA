#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, x;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head;   // making list circular

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    return 0;
}