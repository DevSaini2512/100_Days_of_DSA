#include <stdio.h>

int stack[100];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("%d\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int n, op, val, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d", &val);
            push(val);
        }
        else if(op == 2)
        {
            pop();
        }
        else if(op == 3)
        {
            display();
        }
    }

    return 0;
}