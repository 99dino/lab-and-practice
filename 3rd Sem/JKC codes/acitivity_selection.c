#include <stdio.h>

struct
{
    int finish;
    int start;
} typedef activity;

void swap(activity *a, activity *b)
{
    activity temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(activity arr[], int i, int n)
{
    int min = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left].finish > arr[min].finish)
        min = left;
    if (right <= n && arr[right].finish > arr[min].finish)
        min = right;
    if (min != i)
    {
        swap(&arr[min], &arr[i]);
        max_heapify(arr, min, n);
    }
}

void build_max_heap(activity arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(arr, i, n);
        // max_heapify(arr,i,n);
    }
}

void heap_sort(activity arr[], int n)
{
    build_max_heap(arr, n);
    while (n > 1)
    {
        swap(&arr[1], &arr[n]);
        n--;
        max_heapify(arr, 1, n);
    }
}

int select_activity(activity arr[], int n)
{
    int f = arr[1].finish, max = 1;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i].start >= f)
        {
            max++;
            f = arr[i].finish;
        }
    }
    return max;
}

int main()
{
    int n;
    printf("Total no of activities : ");
    scanf("%d", &n);
    /* activity indexing from 1 to n */
    activity arr[n + 1];
    printf("Enter start time of activities in sequence\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i].start);
    printf("Enter finish time of activities respectively\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i].finish);
    heap_sort(arr, n);
    printf("Maximum activity can be selected is %d", select_activity(arr, n));
    return 0;
}

/*
n : 11

start time
1 3 0 5 3 5 6 8 8 2 12
^     ^       ^      ^
finish time
4 5 6 7 8 9 10 11 12 13 14
^     ^        ^         ^

ans = 4
 */