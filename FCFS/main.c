#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes  Burst time  Waiting time  Turnaround time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n",total_wt / n);
    printf("Average turnaround time = %.2f\n",total_tat / n);
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

    printf("FCFS Scheduling:\n");
    findAvgTime(processes, n, burst_time);

    return 0;
}
