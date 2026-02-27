#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int x, i;

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

    return head;
}

int length(struct node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int main()
{
    int n, m, i;
    struct node *list1, *list2;

    scanf("%d", &n);
    list1 = createList(n);

    scanf("%d", &m);
    list2 = createList(m);

    int len1 = length(list1);
    int len2 = length(list2);

    struct node *p = list1;
    struct node *q = list2;

    int diff = abs(len1 - len2);

    if(len1 > len2)
    {
        for(i = 0; i < diff; i++)
            p = p->next;
    }
    else
    {
        for(i = 0; i < diff; i++)
            q = q->next;
    }

    while(p != NULL && q != NULL)
    {
        if(p->data == q->data)
        {
            printf("%d", p->data);
            return 0;
        }

        p = p->next;
        q = q->next;
    }

    printf("No Intersection");

    return 0;
}