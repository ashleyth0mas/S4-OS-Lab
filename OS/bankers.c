#include <stdio.h>
#include <stdlib.h>
int main()
{
    int np, nr, alloc[20][20], max[20][20], work[10], available[10], need[20][20], req[10], index, i, j, finish[10], count = 0, safeseq[10], r = -1, flag, pos;

    printf("Enter no of processes:");
    scanf("%d", &np);
    printf("\nEnter no of resources:");
    scanf("%d", &nr);
    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\nEnter the max matrix:\n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);
    }
    printf("\nEnter the available matrix:\n");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    for (i = 0; i < np; i++)
    {
        finish[i] = 0;
    }
    printf("\nNeed matrix:\n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t\t", need[i][j]);
        }
        printf("\n");
    }
    while (count < np)
    {
        for (i = 0; i < np; i++)
        {
            int flag = 0;
            if (finish[i] == 0)
            {
                for (j = 0; j < nr; j++)
                {

                    if (need[i][j] <= work[j])
                    {
                        flag++;
                    }
                }

                if (flag == nr)
                {
                    for (j = 0; j < nr; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    count++;
                    finish[i] = 1;
                    safeseq[++r] = i + 1;
                }
            }
        }
    }

    for (i = 0; i < np; i++)
    {

        printf("\nSafesequence:");
        for (i = 0; i < np; i++)
            printf("P%d", safeseq[i]);
    }
    // RESOURCE REQUEST
    printf("\nInput the resource request:");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &req[i]);
    }
    for (i = 0; i < np; i++)
    {
        flag = 0;
        for (j = 0; j < nr; j++)
        {

            if (req[j] <= need[i][j] && req[j] <= available[j])
            {
                flag++;
            }
            if (flag == nr)
            {
                for (j = 0; j < nr; j++)
                {
                    alloc[index - 1][j] += req[j];
                    available[j] -= req[j];
                    need[index - 1][j] -= req[j];
                    pos = i + 1;
                }
                printf("Request satisfied by P%d", pos);
                printf("\n\nAllocation:\n");
                for (j = 0; j < nr; j++)
                {
                    printf("%d\t", alloc[i][j]);
                }
                printf("\n\nAvailable:\n");
                for (j = 0; j < nr; j++)
                {
                    printf("%d\t", available[j]);
                }
                printf("\n\nNeed:\n");
                for (j = 0; j < nr; j++)
                {
                    printf("%d\t", need[i][j]);
                }

                break;
            }
        }
        if (flag == nr)
            break;
    }
}