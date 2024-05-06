// Q01. Implement a program for Process Scheduling algorithm – FCFS scheduling

#include<stdio.h>
// #include<conio.h>

struct process
{
    int pid, arrival, burst, scheduling, completion, turnAround, waiting;
};

float avgTurnAround = 0, avgWaiting = 0;

void sortProcessesAT(struct process p[], int n)
{
    int i, j;
    struct process tempProcess;
    // Sorting the processes according to their arrival time
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].arrival > p[j].arrival)
            {
                tempProcess = p[i];
                p[i] = p[j];
                p[j] = tempProcess;
            }
        }
    }
}

void calculateCompletionTime(struct process p[], int n)
{
    int i;
    // Calculating the completion time of each process using scheduling time
    p[0].scheduling = p[0].arrival;
    p[0].completion = p[0].scheduling + p[0].burst;
    for(i = 1; i < n; i++)
    {
        p[i].scheduling = p[i - 1].completion;
        p[i].completion = p[i].scheduling + p[i].burst;
    }
}

void calculateTATWT(struct process p[], int n)
{
    int i;
    // Calculating the turn around time and waiting time of each process
    for(i = 0; i < n; i++)
    {
        p[i].turnAround = p[i].completion - p[i].arrival;
        avgTurnAround += p[i].turnAround;
        p[i].waiting = p[i].turnAround - p[i].burst;
        avgWaiting += p[i].waiting;
    }
}

void sortProcessesPID(struct process p[], int n)
{
    int i, j;
    struct process tempProcess;
    // Sorting the processes according to their process id
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(p[j].pid > p[j + 1].pid)
            {
                tempProcess = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempProcess;
            }
        }
    }
}

void printProcesses(struct process p[], int n)
{
    int i;
    printf("\nPID\tArrival\tBurst\tScheduling\tCompletion\tTurn Around\tWaiting");
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d", 
        p[i].pid, p[i].arrival, p[i].burst, p[i].scheduling, 
        p[i].completion, p[i].turnAround, p[i].waiting);
    }
    printf("\n\nAverage Turn Around Time: %.2f", avgTurnAround / n);
    printf("\nAverage Waiting Time: %.2f", avgWaiting / n);
}

void printGanttChart(struct process p[], int n)
{
    int i, j;
    printf("\n\nGantt Chart:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t", p[i].pid);
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", p[i].scheduling);
    }
    printf("%d\t", p[n - 1].completion);
}

int main()
{
    int i, n;
    // clrscr();
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the arrival time and burst time of each process:\n");
    for(i = 0; i < n; i++)
    {
        //printf("Process %d:\n", i + 1);
        p[i].pid = i + 1;
        //printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        //printf("Burst Time: ");
        scanf("%d", &p[i].burst);
    }
    sortProcessesAT(p, n);
    calculateCompletionTime(p, n);
    calculateTATWT(p, n);
    sortProcessesPID(p, n);
    printProcesses(p, n);
    printGanttChart(p, n);
    // getch();
    return 0;
}

/*
Output:
Enter the number of processes: 4
Enter the arrival time and burst time of each process:
0 3
1 5
2 2
4 4

PID     Arrival Burst   Scheduling      Completion      Turn Around     Waiting
1       0       3       0               3               3               0
2       1       5       3               8               7               2
3       2       2       8               10              8               6
4       4       4       10              14              10              6

Average Turn Around Time: 7.00
Average Waiting Time: 3.50

Gantt Chart:
P1      P2      P3      P4
0       3       8       10      14
*/