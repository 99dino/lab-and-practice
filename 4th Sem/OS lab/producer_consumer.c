#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct Queue
{
    int buffer[100];
    int front, size, in, out;
};

int isempty(struct Queue q)
{
    return (q.size == 0 ? 1 : 0);
}

int produce(struct Queue *que)
{
    if ((*que).in == (*que).size)
    {
        return -1;
    }
    srand(time(NULL));
    (*que).buffer[(*que).in++] = rand();
}

int consume(struct Queue *que)
{
    if ((*que).in == (*que).out)
    {
        return -1;
    }
    return (*que).buffer[(*que).out++];
}

int main()
{
    struct Queue que;
    que.in = que.out = que.front = 0;
    que.size = 10;
    int a;
    do
    {
        printf("1.Produce\n2.Consume\n0.Break\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Produced %d\n", produce(&que));
            // printf("-->%d\n",(find_max(array,n)).key);
            break;
        case 2:
            printf("Consumed %d\n", consume(&que));

            // printf("-->%d\n",(extract_max(array,&n)).key);
            break;
        case 0:
            break;
        default:
            printf("-->incorrect choice.\n");
        }
    } while (a);
}