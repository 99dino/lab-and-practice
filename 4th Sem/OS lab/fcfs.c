#include <stdio.h>

typedef struct Process
{
    char pid[10];
    int AT, BT, WT, TAT, CT;

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
            {
                swap(&pro[j], &pro[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter no of process: ");
    scanf("%d", &n);
    Process pro[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter pid, Arrival time and Burst time : ");
        scanf("%s", pro[i].pid);
        scanf("%d%d", &pro[i].AT, &pro[i].BT);
        pro[i].WT = 0;
        pro[i].TAT = 0;
    }
    sort(pro, n);

    printf("\n-------------------------------------------------\n");
    printf("|\tPID\t|\tAT\t|\tBT\t|\n");
    for (int i = 0; i < n; i++)
    {
        printf("-------------------------------------------------\n");
        printf("|\t%s\t|\t%d\t|\t%d\t|\n", pro[i].pid, pro[i].AT, pro[i].BT);
    }
    printf("-------------------------------------------------\n\n");

    // waiting_time(pro, n);
    // turn_around_time(pro, n);
    int total_TAT = 0, total_WT = 0, clk = pro[0].AT, idle = 0;
    printf("Process scheduling as follows\n");

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("|\tPID\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    for (int i = 0; i < n; i++)
    {
        clk += pro[i].BT;
        pro[i].CT = clk;
        pro[i].TAT = pro[i].CT - pro[i].AT;
        pro[i].WT = pro[i].TAT - pro[i].BT + idle;
        if (pro[i].WT < 0)
            pro[i].WT = 0, idle = -pro[i].WT;

        printf("-------------------------------------------------------------------------------------------------\n");
        printf("|\t%s\t|\t", pro[i].pid);
        printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
        total_WT += pro[i].WT;
        total_TAT += pro[i].TAT;
    }
    printf("-------------------------------------------------------------------------------------------------\n\n");
    printf("Average waiting time is : %f\n", (float)(total_WT) / n);
    printf("Average turn around time is : %f\n", (float)(total_TAT) / n);
}

/*

4
p1 5 12
p2 4 7
p3 6 10
p4 2 5

 */

/*

5
P1	3	4
P2	5	3
P3	0	2
P4	5	1
P5	4	3
wt=3.2
tat=5.8


 */