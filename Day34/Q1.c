#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL) return 0;

    int val = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[200];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();
            int res;

            if(token[0] == '+') res = a + b;
            else if(token[0] == '-') res = a - b;
            else if(token[0] == '*') res = a * b;
            else if(token[0] == '/') res = a / b;

            push(res);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}