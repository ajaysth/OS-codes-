#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct {
    int id;
    int arrival;
    int burst;
    int done;
    int around;
    int wait;
    int remain;
} Process;

// Function to perform SRTF scheduling
void srtf(Process *procs, int n) {
    int time = 0; // Current time
    int completed = 0; // Number of completed processes

    while (completed < n) {
        int shortest = 9999; // Set to a large value
        int index = -1;

        // Find the process with the shortest remaining time among arrived processes
        for (int i = 0; i < n; i++) {
            if (procs[i].arrival <= time && procs[i].remain < shortest && procs[i].remain > 0) {
                shortest = procs[i].remain;
                index = i;
            }
        }

        // If no process is found, increment time
        if (index == -1) {
            time++;
            continue;
        }

        // Execute the shortest remaining time process
        procs[index].remain--;
        time++;

        // Check if the process is completed
        if (procs[index].remain == 0) {
            completed++;
            procs[index].done = time;
            procs[index].around = procs[index].done - procs[index].arrival;
            procs[index].wait = procs[index].around - procs[index].burst;
            printf("%d \t%d \t%d \t%d \t%d\n", procs[index].arrival, procs[index].burst, procs[index].done, procs[index].around, procs[index].wait);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *procs = (Process *)malloc(n * sizeof(Process));

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &procs[i].arrival, &procs[i].burst);
        procs[i].id = i + 1;
        procs[i].remain = procs[i].burst;
    }

    // Perform SRTF scheduling
    printf("A.T \tB.T \tC.T \tT.A.T \tW.T\n");
    srtf(procs, n);

    free(procs);
    return 0;
}