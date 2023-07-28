#include <stdio.h>

int main()
{
    int block_count, process_count;

    printf("Enter no of Blocks : ");
    scanf("%d", &block_count);
    printf("Enter no of Processes : ");
    scanf("%d", &process_count);
    int blocks[block_count];
    int processes[process_count];
    int process_in_block[process_count];

    printf("Enter block size of %d blocks.\n", block_count);
    for (int i = 0; i < block_count; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("Enter process size of %d process.\n", process_count);
    for (int i = 0; i < process_count; i++)
    {
        scanf("%d", &processes[i]);
        process_in_block[i] = -1;
    }
    for (int i = 0; i < process_count; i++)
    {
        int ind = 0;
        for (int j = 1; j < block_count; j++)
        {
            if (blocks[ind] <= blocks[j])
            {
                ind = j;
            }
        }
        if (processes[i] <= blocks[ind])
        {
            process_in_block[i] = ind + 1;
            // blocks[ind] -= processes[i];
            blocks[ind] = 0;
        }
    }

    printf("-1 denotes that memory is not allocated for some process.\n");
    printf("Process\t\tBlock\n");
    for (int i = 0; i < process_count; i++)
    {
        printf("%d\t\t%d\n", processes[i], process_in_block[i]);
    }
    return 0;
}
/*

5 4
100 500 200 300 600
212 417 112 426

 */