#include <stdio.h>

typedef struct Process
{
    char pid[10];
    int BT, WT, TAT, AT, CT;
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
            if (pro[j].BT > pro[j + 1].BT)
                swap(&pro[j], &pro[j + 1]);
        }
    }
}

// void waiting_time(Process pro[], int n)
// {
//     for (int i = 1; i < n; i++)
//         pro[i].WT += pro[i - 1].WT + pro[i - 1].BT;
// }

// void turn_around_time(Process pro[], int n)
// {
//     for (int i = 0; i < n; i++)
//         pro[i].TAT += pro[i].WT + pro[i].BT;
// }

int main()
{
    int n;
    printf("Enter no of process: ");
    scanf("%d", &n);
    Process pro[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter pid,Burst time : ");
        scanf("%s", pro[i].pid);
        scanf("%d", &pro[i].BT);
        pro[i].WT = 0;
        pro[i].TAT = 0;
        pro[i].AT = 0;
    }
    sort(pro, n);
    printf("\n---------------------------------\n");
    printf("|\tPID\t|\tBT\t|\n");
    for (int i = 0; i < n; i++)
    {
        printf("---------------------------------\n");
        printf("|\t%s\t|\t%d\t|\n", pro[i].pid, pro[i].BT);
    }
    printf("---------------------------------\n\n");

    //    waiting_time(pro, n);
    //  turn_around_time(pro, n);

    int total_TAT = 0, total_WT = 0, clk = pro[0].AT;
    printf("Process scheduling as follows\n");

    printf("\n---------------------------------------------------------------------------------\n");
    printf("|\tPID\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    for (int i = 0; i < n; i++)
    {
        clk += pro[i].BT;
        pro[i].CT = clk;
        pro[i].TAT = pro[i].CT - pro[i].AT;
        pro[i].WT = pro[i].TAT - pro[i].BT;
        printf("---------------------------------------------------------------------------------\n");
        printf("|\t%s\t|\t", pro[i].pid);
        printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\n", pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
        total_WT += pro[i].WT;
        total_TAT += pro[i].TAT;
    }
    printf("---------------------------------------------------------------------------------\n\n");
    printf("Average waiting time is : %f\n", (float)(total_WT) / n);
    printf("Average turn around time is : %f\n", (float)(total_TAT) / n);
}
/*

3
p1 5
p2 10
p3 3

 */