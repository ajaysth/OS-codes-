#include<stdio.h>

int main() {
    int q[20], p[50], c=0, c1, d, f, i, j, k=0, n, r, t, b[20], c2[20];

    // Input number of pages
    printf("Enter the number of pages:");
    scanf("%d", &n);

    // Input the reference string
    printf("Enter the reference string:");
    for(i=0; i<n; i++)
        scanf("%d", &p[i]);

    // Input number of frames
    printf("Enter the number of frames:");
    scanf("%d", &f);

    // Initialize the first frame
    q[k] = p[k];
    printf("\n\t%d\n", q[k]);
    c++;
    k++;

    // Loop through the reference string
    for(i=1; i<n; i++) {
        c1 = 0;

        // Check if page already exists in frames
        for(j=0; j<f; j++) {
            if(p[i] != q[j])
                c1++;
        }

        // If page is not found in frames
        if(c1 == f) {
            c++; // Increment page fault count
            if(k < f) { // If frames are not full
                q[k] = p[i]; // Add the page to the frame
                k++;
                for(j=0; j<k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            } else { // If frames are full
                for(r=0; r<f; r++) {
                    c2[r] = 0;

                    // Calculate distance of each page from the current position in the reference string
                    for(j=i-1; j<n; j--) {
                        if(q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }

                // Copy the distances into a temporary array
                for(r=0; r<f; r++)
                    b[r] = c2[r];

                // Sort the distances in descending order
                for(r=0; r<f; r++) {
                    for(j=r; j<f; j++) {
                        if(b[r] < b[j]) {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }

                // Find the page with maximum distance
                for(r=0; r<f; r++) {
                    if(c2[r] == b[0])
                        q[r] = p[i];
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    // Output the total number of page faults
    printf("\nThe number of page faults is %d", c);
    return 0;
}