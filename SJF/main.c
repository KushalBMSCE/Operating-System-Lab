#include <stdio.h>

void sortProcessesByBurst(int n, int processes[], int bt[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void findWaitingTimeSJF(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTimeSJF(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTimeSJF(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    sortProcessesByBurst(n, processes, bt);
    findWaitingTimeSJF(processes, n, bt, wt);
    findTurnAroundTimeSJF(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Waiting time  Turnaround time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes \n");
    scanf("%d",&n);
    int processes[n];
    for(int i=0; i<n; i++){
        processes[i]=i+1;
    }
    int burst_time[n];
    printf("Enter the burst time of \n");
    for(int i=0; i<n; i++){
        printf("Process %d : ",i+1);
        scanf("%d",&burst_time[i]);
    }

    printf("SJF Scheduling:\n");
    findAvgTimeSJF(processes, n, burst_time);

    return 0;
}
