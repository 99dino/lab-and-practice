#include <stdio.h>
int main()
{
    int n, m;
    printf("LRU page replacement algorithm....\n");
    printf("enter the no. of frames:");
    scanf("%d", &n);
    int frames[n + 1], lru[n];
    for (int i = 0; i < n; i++)
    {
        lru[i] = 0;
        frames[i] = -1;
    }
    printf("enter the reference string size: ");
    scanf("%d", &m);
    printf("enter the reference string/page: ");
    int page[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &page[i]);
    }
    int start = 1, fault = 0, hit = 0;
    for (int i = 0; i < m; i++)
    {
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (frames[j] == page[i])
            {
                printf("\n%d is already present( i.e. HIT)\n", page[i]);
                flag = 0;
                lru[j] = start;
                hit++;
                break;
            }
        }
        if (flag == 1)
        {
            int smallest = 0;
            for (int j = 1; j < n; j++)
            {
                if (lru[j] < lru[smallest])
                    smallest = j;
            }
            printf("\n%d is added at frame no %d\n-> ", page[i], smallest);
            frames[smallest] = page[i];
            lru[smallest] = start;
            for (int j = 0; j < n; j++)
            {
                printf("|");
                if (frames[j] != -1)
                {
                    printf("%d", frames[j]);
                }
                else
                {
                    printf("*");
                }
            }
            printf("|\n");
            fault++;
        }
        start++;
    }
    printf("\ntotal no page hits=%d\n", hit);
    printf("total no page faults=%d\n", fault);
}

/*
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/