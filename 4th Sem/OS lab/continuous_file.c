// a) Continuous Allocation
#include <stdio.h>
#include <stdlib.h>

struct file
{
    char name[20];
    int start;
    int length;

} f[100];

int main()
{
    int n;

    printf("Enter the number of total files to be stored in the disk : \n");
    scanf("%d", &n);

    int disk[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the file name for file %d : ", i + 1);
        scanf("%s", f[i].name);

        printf("Enter the start location of the file : ");
        scanf("%d", &f[i].start);

        printf("Enter the length of file : ");
        scanf("%d", &f[i].length);

        int flag = 0;

        for (int j = f[i].start; j < f[i].start + f[i].length; j++)
        {
            if (disk[j] != 0)
            {
                printf("Not enough memory to allocate Continously to the process!!!!  \n");
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            for (int j = f[i].start; j < f[i].start + f[i].length; j++)
                disk[j] = i + 1;
        }
    }

    printf("\nDisk usage : ");
    printf("\n------------------------------------------\n");
    for (int i = 0; i < 50; i++)
    {
        if (i % 10 == 0 && i != 0)
            printf(" |\n------------------------------------------\n");
        if (disk[i] == 0)
            printf("|   ");
        else
            printf("| %d ", disk[i]);
    }
    printf(" |\n------------------------------------------\n");

    return 0;
}
