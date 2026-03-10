#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return ((front == 0 && rear == MAX-1) || (front == rear + 1));
}

void push_front(int x)
{
    if(isFull())
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = x;
}

void push_back(int x)
{
    if(isFull())
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if(isEmpty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
}

void pop_back()
{
    if(isEmpty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display()
{
    if(isEmpty())
        return;

    int i = front;

    while(1)
    {
        printf("%d ", deque[i]);
        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    pop_front();   // removes 5
    pop_back();    // removes 30

    display();     // remaining elements

    return 0;
}