#include <stdio.h>
#include <stdlib.h>

// Function to simulate page faults
int page_fault(int a[], int frame[], int n, int no) {
    int i, j, is_available, count = 0, k;

    // Initialize frame with value -1 (indicating empty frame)
    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }
    j = 0; // Index to track the position to insert new pages

    // Iterate over the page reference sequence
    for (i = 0; i < n; i++) {
        is_available = 0; // Flag to check if page is available in frame
        for (k = 0; k < no; k++) {
            // If page number (reference) is found in frame
            if (frame[k] == a[i]) {
                is_available = 1;
                break;
            }
        }
        // If the page is not available in frame, a page fault occurs
        if (is_available == 0) {
            // Add the page to the frame
            frame[j] = a[i];
            // Move to the next position for inserting new pages
            j = (j + 1) % no;
            // Increment the page fault count
            count++;
        }
    }
    // Return the total number of page faults
    return count;
}

int main() {
    int n, i, *a, *frame, no, fault;

    // Input the number of pages
    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    // Allocate memory for the page reference sequence
    a = (int *)malloc(n * sizeof(int));
    printf("ENTER THE PAGE NUMBERS:\n");
    // Input the page numbers
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Input the number of frames
    printf("ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);

    // Allocate memory for the frame
    frame = (int *)malloc(no * sizeof(int));
    // Simulate page faults
    fault = page_fault(a, frame, n, no);
    // Output the number of page faults
    printf("Page Faults: %d", fault);

    // Free dynamically allocated memory
    free(a);
    free(frame);

    return 0;
}