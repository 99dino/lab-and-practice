#include <stdio.h>
int main()
{
    int n, m;
    printf("FIFO page replacement algorithm....\n");
    printf("enter the no. of frames:");
    scanf("%d", &n);
    int frames[n + 1];
    for (int i = 0; i < n; i++)
    {
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
    int start = 0, fault = 0, hit = 0;
    for (int i = 0; i < m; i++)
    {
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (frames[j] == page[i])
            {
                printf("%d is already present( i.e. HIT)\n", page[i]);
                flag = 0;
                hit++;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d is added at frame no %d\n", page[i], start);
            frames[start] = page[i];
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
            start = (start + 1) % n;
            fault++;
        }
    }
    printf("total no page hits=%d\n", hit);
    printf("total no page faults=%d\n", fault);
}

/*
4
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/