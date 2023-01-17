#include <stdio.h>
#include "my_functions.h"

struct time
{
    int arrival;
    int burst;
    int waiting;
    
};

void sort(struct time process[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (process[i].burst > process[j].burst)
            {
                struct time temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
}

float average(int arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        sum += arr[i];
    }
    float result = sum / (float)size;
    return result;
}

void waitingTime(struct time process[], int size)
{
    process[0].waiting = 0;
    for (int i = 1; i < size; i++)
    {
        process[i].waiting = process[i - 1].burst + process[i - 1].waiting;
    }
    printf("Waiting time of processes: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", process[i].waiting);
    }
    printf("\nThe average waiting time is: %f\n", average(&process[1].waiting, size));
}

int main()
{
    int size;
    printf("Enter the number of processes: ");
    scanf("%d", &size);
    struct time process[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the burst time of %d process : ", i + 1);
        scanf("%d", &process[i].burst);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the arrival time of %d process : ", i + 1);
        scanf("%d", &process[i].arrival);
    }
    sort(process, size);
    waitingTime(process, size);
    return 0;
}