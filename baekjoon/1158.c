#include <stdio.h>

struct queue
{
    int arr[5001];
    int front;
    int rear;
};

// Constructor replaced with an initializer function for C
void push(struct queue* q, int x)
{
    q->rear = q->rear % 5001;
    q->arr[q->rear++] = x;
}

int pop(struct queue* q)
{
    q->front = q->front % 5001;
    return q->arr[q->front++];
}

int size(struct queue* q)
{
    return (q->rear - q->front + 5001) % 5001;
}   

int empty(struct queue* q)
{
    return q->front == q->rear;
}

int getFront(struct queue* q)
{
    int front = q->front;
    return q->arr[front];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    struct queue q = {.front = 0, .rear = 0};
    for(int i = 1; i <= n; i++)
        push(&q, i);
    
    printf("<");
    while(size(&q) > 1)
    {
        for(int i = 0; i < k - 1; i++)
        {
            int temp = pop(&q);
            push(&q, temp);
        }
            printf("%d, ", pop(&q));
    }
    printf("%d>", pop(&q));

    return 0;
}