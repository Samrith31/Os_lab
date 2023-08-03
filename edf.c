#include <stdio.h>
#define MAX_TASKS 100
typedef struct
{
    int task_id;
    int arrival_time;
    int execution_time;
    int deadline;
    int is_completed;
} Task;

float calculate_cpu_utilization(Task process[], int n)
{
    float total_utilization = 0.0;
    for (int i = 0; i < n; i++)
    {
        float task_utilization = (float)process[i].execution_time / process[i].deadline;
        total_utilization += task_utilization;
    }
    float cpu_utilization = total_utilization * 100;
    return cpu_utilization;
}
int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Task process[MAX_TASKS];
    for (i = 0; i < n; i++)
    {
        printf("Process % d\n", i + 1);
        printf("Enter execution time:");
        scanf("%d", &process[i].execution_time);
        printf("Enter deadline:");
        scanf("%d", &process[i].deadline);
        process[i].task_id = i + 1;
        process[i].is_completed = 0;
    }
        float cpu_utilization = calculate_cpu_utilization(process, n);
    printf("CPU Utilization: % .2f % %\n"
           , cpu_utilization);
    return 0;
}
