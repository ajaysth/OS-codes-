#include<stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    // Initialize flags and allocation arrays
    for(i = 0; i < 10; i++)
    {
        flags[i] = 0;       // flags array to indicate whether a block is allocated or not (0 for not allocated, 1 for allocated)
        allocation[i] = -1; // allocation array to store the index of the process allocated to each block (-1 for not allocated)
    }

    // Input the number of blocks
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);

    // Input the size of each block
    printf("\nEnter size of each block: ");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    // Input the number of processes
    printf("\nEnter no. of processes: ");
    scanf("%d", &pno);

    // Input the size of each process
    printf("\nEnter size of each process: ");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    // First Fit allocation
    for(i = 0; i < pno; i++)
    {
        for(j = 0; j < bno; j++)
        {
            // If the block is not allocated and has sufficient size for the process
            if(flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;  // Allocate the process to this block
                flags[j] = 1;       // Set the flag indicating the block is allocated
                break;              // Break the loop to allocate only one process to each block
            }
        }
    }

    // Display allocation details
    printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
    for(i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
        if(flags[i] == 1)
            printf("%d\t\t\t%d", allocation[i]+1, psize[allocation[i]]);
        else
            printf("Not allocated");
    }
}