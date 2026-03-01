#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, x, k;
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

    scanf("%d", &k);

    temp = head;
    int count = 1;

    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    temp->next = head;   // make circular

    k = k % count;
    int steps = count - k;

    struct node *curr = head;
    for(i = 1; i < steps; i++)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}