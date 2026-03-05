#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    
    char pid[20][10];
    int at[20], bt[20], pr[20];
    int rt[20], ct[20], tat[20], wt[20];
    
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time, Burst Time and Priority for process %d: ", i+1);
        scanf("%s %d %d %d", pid[i], &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed < n) {
        int idx = -1;
        int best_pr = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                ct[idx] = time;
                completed++;
            }
        } 
        else {
            time++;
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nWaiting Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", pid[i], wt[i]);

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++)
        printf("%s %d\n", pid[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
