#include <stdio.h>

typedef struct Process
{
    char pid[10];
    int AT, BT, WT, TAT, REM_TIME, CT;
} Process;

void swap(Process *a, Process *b)
{
    Process t = *a;
    *a = *b;
    *b = t;
}

void sort(Process pro[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (pro[j].AT > pro[j + 1].AT)
                swap(&pro[j], &pro[j + 1]);
        }
    }
}

void min_heapify(Process pro[], int i, int n)
{
    int min = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && pro[left].BT < pro[min].BT)
        min = left;
    if (right <= n && pro[right].BT < pro[min].BT)
        min = right;
    if (min != i)
    {
        swap(&pro[min], &pro[i]);
        min_heapify(pro, min, n);
    }
}

void build_min_heap(Process pro[], int n)
{
    for (int i = n / 2; i > 0; i--)
        min_heapify(pro, i, n);
}

void decrease_key(Process pro[], int i, int size)
{
    int key = pro[i].BT;
    while (i > 1 && pro[i / 2].BT > key)
    {
        swap(&pro[i], &pro[i / 2]);
        i /= 2;
    }
}

Process extract_min(Process pro[], int *size)
{
    Process temp = pro[1];
    pro[1] = pro[*size];
    (*size)--;
    min_heapify(pro, 1, *size);
    return temp;
}

void insert(Process pro[], int *size, Process newproc)
{
    (*size)++;
    pro[*size] = newproc;
    decrease_key(pro, *size, *size);
}

int main()
{
    int n, m = 0;
    printf("Enter no of process: ");
    scanf("%d", &n);
    Process pro[n + 1], arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter pid, Arrival time and Burst time : ");
        scanf("%s", arr[i].pid);
        scanf("%d%d", &arr[i].AT, &arr[i].BT);
        arr[i].WT = 0;
        arr[i].REM_TIME = arr[i].BT;
        arr[i].TAT = 0;
    }
    sort(arr, n);
    printf("\n-------------------------------------------------\n");
    printf("|\tPID\t|\tAT\t|\tBT\t|\n");
    for (int i = 0; i < n; i++)
    {
        printf("-------------------------------------------------\n");
        printf("|\t%s\t|\t", arr[i].pid);
        printf("%d\t|\t%d\t|\n", arr[i].AT, arr[i].BT);
    }
    printf("-------------------------------------------------\n\n");

    int clk = 0, ind = 0;
    printf("Process scheduling as follows\n");

    // printf("PID\t\tAT\t\tBT\t\tWT\t\tTAT\n");
    for (int i = 0; i < n;)
    {
        if (m == 0)
            insert(pro, &m, arr[i++]);
        if (clk == -1)
        {
            clk = pro[1].AT;
        }
        Process t = extract_min(pro, &m);
        printf("->( CLOCK=%d ) \t: %s ", clk, t.pid);
        printf("executed for %d ms\n", t.REM_TIME);
        clk += t.REM_TIME;
        // t.WT = clk;
        t.CT = clk;
        t.TAT = t.CT - t.AT;
        t.WT = t.TAT - t.BT;
        arr[ind++] = t;
        while (i < n && arr[i].AT < clk)
        {
            insert(pro, &m, arr[i++]);
        }
    }
    while (m)
    {
        Process t = extract_min(pro, &m);
        printf("->( CLOCK=%d ) \t: %s ", clk, t.pid);
        printf("executed for %d ms\n", t.REM_TIME);
        clk += t.REM_TIME;
        // t.WT = clk;
        t.CT = clk;
        t.TAT = t.CT - t.AT;
        t.WT = t.TAT - t.BT;
        arr[ind++] = t;
    }

    printf("------------------------------------------");
    printf("-------------------------------------------------------\n");

    int total_TAT = 0, total_WT = 0;
    printf("|\tPID\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    for (int i = 0; i < n; i++)
    {
        printf("------------------------------------------");
        printf("-------------------------------------------------------\n");
        printf("|\t%s\t|\t", arr[i].pid);
        printf("%d\t|\t%d\t|", arr[i].AT, arr[i].BT);
        printf("\t%d\t|\t%d\t|\t%d\t|\n", arr[i].CT, arr[i].TAT, arr[i].WT);
        total_WT += arr[i].WT;
        total_TAT += arr[i].TAT;
    }
    printf("-----------------------------------------");
    printf("--------------------------------------------------------\n\n");
    printf("Average waiting time is : %f\n", (float)(total_WT) / n);
    printf("Average turn around time is : %f\n", (float)(total_TAT) / n);
}

/*

4
p1 0 10
p2 5 5
p3 11 3
p4 2 8

*/

/*
5
P1	3	1
P2	1	4
P3	4	2
P4	0	6
P5	2	3
wt=4.8
tat=8


 */