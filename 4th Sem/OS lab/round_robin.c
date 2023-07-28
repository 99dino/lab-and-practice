// #include <stdio.h>
// #include <string.h>

// struct Process
// {
//     char pid[10];
//     int BT;
//     int no_of_cycles;
// };

// struct Queue
// {
//     struct Process pro[100];
//     int front;
//     int size;
// };

// int isempty(struct Queue q)
// {
//     return (q.size == 0 ? 1 : 0);
// }

// void enqueue(struct Queue *q, struct Process p)
// {
//     if ((*q).size == 100)
//     {
//         printf("Wait.\n");
//         return;
//     }
//     (*q).pro[((*q).front + (*q).size) % 100] = p;
//     (*q).size++;
//     // printf("%d\n",(*q).size);
//     // printf("Process is in Ready Queue.\n");
// }

// struct Process dequeue(struct Queue *q)
// {
//     struct Process p;
//     if ((*q).size == 0)
//     {
//         printf("Nothing left to execute.\n");
//         return p;
//     }
//     p = (*q).pro[(*q).front];
//     (*q).front++;
//     (*q).size--;
//     return p;
// }

// int main()
// {
//     int Quanta_time = 4; // 4 ms
//     int n;
//     printf("Enter no of process : ");
//     scanf("%d", &n);
//     struct Process pro;
//     struct Queue q;
//     q.front = 0;
//     q.size = 0;
//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter PID and its total execution time : ");
//         scanf("%s", (pro.pid));
//         scanf("%d", &(pro.BT));
//         pro.no_of_cycles = 0;
//         enqueue(&q, pro);
//     }

//     printf("\n---------------------------------\n");
//     printf("|\tPID\t|\tBT\t|\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("---------------------------------\n");
//         printf("|\t%s\t|\t%d\t|\n", q.pro[i].pid, q.pro[i].BT);
//     }
//     printf("---------------------------------\n\n");
//     printf("---------ROUND ROBIN Scheduling-----------\n");
//     while (!isempty(q))
//     {
//         struct Process p = dequeue(&q);
//         p.no_of_cycles++;
//         int time = (p.BT > Quanta_time ? Quanta_time : p.BT);
//         printf("(pid : %s) executed for %d ms.\n", p.pid, time);
//         if (p.BT > Quanta_time)
//         {
//             p.BT -= Quanta_time;
//             enqueue(&q, p);
//         }
//     }
//     printf("------------------------------------------\n\n");
// }

// /*

// 4
// p1 20
// p2 14
// p3 11
// p4 9

//  */
// /*

// 5
// P1	5
// P2	3
// P3	1
// P4	2
// P5	3
// wt=5.8
// tat=8.6
//  */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    srand(time(NULL));
    int r = rand();
    printf("%d", r);
}