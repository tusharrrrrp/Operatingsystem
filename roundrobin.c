#include <stdio.h>

void rr_scheduling(int n, int bt[], int quantum) {
    int rem_bt[n], wt[n] = {0}, t = 0, total_wt = 0;

    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    for (int i = 0; i < n; i++)
        total_wt += wt[i];

    printf("Average waiting time: %.2f\n", (float)total_wt / n);
}

int main() {
    int n = 4, burst_time[] = {10, 5, 8, 12}, quantum = 2;
    rr_scheduling(n, burst_time, quantum);
    return 0;
}
