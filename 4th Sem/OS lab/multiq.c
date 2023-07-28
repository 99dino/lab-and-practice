#include <stdio.h>
#include <string.h>

struct Process{
    char pid[10];
    int BT;
    int no_of_cycles;
};

struct Queue{
    struct Process pro[100];
    int front;
    int size;
};

int isempty(struct Queue q){
    return (q.size == 0 ? 1 : 0);
}

void enqueue(struct Queue *q, struct Process p){
    if ((*q).size == 100){
        printf("Wait.\n");
        return;
    }
    (*q).pro[((*q).front + (*q).size) % 100] = p;
    (*q).size++;
    // printf("%d\n",(*q).size);
    // printf("Process is in Ready Queue.\n");
}

struct Process dequeue(struct Queue *q){
    struct Process p;
    if ((*q).size == 0){
        printf("Nothing left to execute.\n");
        return p;
    }
    p = (*q).pro[(*q).front];
    (*q).front++;
    (*q).size--;
    return p;
}

int main(){
    int Quanta_time1 = 8;  // 8 ms
    int Quanta_time2 = 16; // 16 ms
    int n;
    printf("Enter no of process : ");
    scanf("%d", &n);
    struct Process pro;
    struct Queue q8, q16, fcfs;
    q8.front = 0;
    q8.size = 0;
    q16.front = 0;
    q16.size = 0;
    fcfs.front = 0;
    fcfs.size = 0;
    for (int i = 0; i < n; i++){
        printf("Enter PID and its total execution time : ");
        scanf("%s", (pro.pid));
        scanf("%d", &(pro.BT));
        pro.no_of_cycles = 0;
        enqueue(&q8, pro);
    }

    printf("\n---------------------------------\n");
    printf("|\tPID\t|\tBT\t|\n");
    for (int i = 0; i < n; i++){
        printf("---------------------------------\n");
        printf("|\t%s\t|\t%d\t|\n", q8.pro[i].pid, q8.pro[i].BT);
    }
    printf("---------------------------------\n\n");

    printf("---------MULTI - LEVEL - QUEUE - SCHEDULING-----------\n");
    printf("\nQueue having Quanta time = 8 ms \n");
    while (!isempty(q8)){
        struct Process p = dequeue(&q8);
        p.no_of_cycles++;
        int time = (p.BT > Quanta_time1 ? Quanta_time1 : p.BT);
        printf("(pid : %s) executed for %d ms.\n", p.pid, time);
        if (p.BT > Quanta_time1)
        {
            p.BT -= Quanta_time1;
            enqueue(&q16, p);
        }
    }
    printf("\nQueue having Quanta time = 16 ms \n");
    while (!isempty(q16)){
        struct Process p = dequeue(&q16);
        p.no_of_cycles++;
        int time = (p.BT > Quanta_time2 ? Quanta_time2 : p.BT);
        printf("(pid : %s) executed for %d ms.\n", p.pid, time);
        if (p.BT > Quanta_time2)
        {
            p.BT -= Quanta_time2;
            enqueue(&fcfs, p);
        }
    }

    printf("\nQueue having Quanta time = infinity ms (FCFS) \n");
    while (!isempty(fcfs)){
        struct Process p = dequeue(&fcfs);
        p.no_of_cycles++;
        printf("(pid : %s) executed for %d ms.\n", p.pid, p.BT);
    }
    printf("-------------------------------------------------------");
}
// burst time is how much time a process is coming in system
/*

8
p1 32
p2 7
p3 10
p4 24
p5 27
p6 3
p7 23
p8 39

 */