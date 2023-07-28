#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct block
{
    int blocknum;
    int fileNum;
    struct block *next;
};

struct file
{
    char name[40];
    int length;
    struct block *start;
} f[100];

int main()
{
    int n;
    printf("Enter the number of files in the disk : ");
    scanf("%d", &n);
    time_t t;
    srand((int)time(&t));
    int disk[1000] = {0};
    int count = 1000;

    // there are some block which are pre-occupied
    for (int i = 0; i < 500; i++)
    {
        int a = rand() % 1000;
        disk[a] = 1;
        count--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of the file : ");
        scanf("%s", f[i].name);

        printf("Enter the length of the blocks : ");
        scanf("%d", &f[i].length);

        if (f[i].length > count)
        {
            printf("No enough memory to allocate this file !!!! \n");
            continue;
        }
        else
        {
            f[i].start = (struct block *)malloc(sizeof(struct block));
            f[i].start->fileNum = i;
            f[i].start->next = NULL;
            int c = -1, k;
            for (k = 0; k < 1000; k++)
            {
                if (disk[k] == 0)
                {
                    c = k;
                    break;
                }
            }

            f[i].start->blocknum = c;
            disk[c] = 1;
            count--;

            struct block *prev = f[i].start;
            for (int j = 1; j < f[i].length; j++)
            {
                struct block *new = (struct block *)malloc(sizeof(struct block));
                new->fileNum = i;
                new->next = NULL;
                for (; k < 1000; k++)
                {
                    if (disk[k] == 0)
                    {
                        c = k;
                        break;
                    }
                }
                new->blocknum = c;
                disk[c] = 1;
                count--;
                prev->next = new;
                prev = new;
            }
        }
    }

    printf("Disk is allocated as follows : \n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nAllocation for File named as : %s\n", f[i].name);
        struct block *temp = f[i].start;
        printf("Block Numbers allocated are : \n");
        while (temp != NULL)
        {
            printf(" -> %d", temp->blocknum);
            temp = temp->next;
        }
        printf("\n\n");
    }
    return 0;
}
