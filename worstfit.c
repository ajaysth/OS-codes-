#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, worst_index;

    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the size of the blocks
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the size of the files
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Worst Fit allocation
    for (i = 1; i <= nf; i++) {
        temp = -1;
        worst_index = -1;
        for (j = 1; j <= nb; j++) {
            if (b[j] >= f[i]) {
                if (worst_index == -1 || b[j] > b[worst_index]) {
                    worst_index = j;
                }
            }
        }
        if (worst_index != -1) {
            temp = worst_index;
            frag[i] = b[worst_index] - f[i];
            b[worst_index] = -1; // Mark the block as allocated
        } else {
            frag[i] = -1; // File not allocated
        }
    }

    // Display allocation details
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for (i = 1; i <= nf; i++) {
        if (frag[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], worst_index, b[worst_index], frag[i]);
        else
            printf("%d\t\t%d\t\t%s\n", i, f[i], "Not Allocated");
    }

    return 0;
}