#include <stdio.h>
#include "my_functions.h"

float average(int arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    float result = sum / (float)size;
    return result;
}

void waitingTime(int bst[], int at[], int size, int timeQuantum)
{
    int wt[size];
    int rem[size];
    int t = 0;
    for (int i = 0; i < size; i++)
    {
        rem[i] = bst[i];
    }
    while (1)
    {
        int done = 1;
        for (int i = 0; i < size; i++)
        {
            if (rem[i] > 0)
            {
                done = 0;
                if (rem[i] > timeQuantum)
                {
                    t += timeQuantum;
                    rem[i] -= timeQuantum;
                }
                else
                {
                    t = t + rem[i];
                    wt[i] = t - bst[i];
                    rem[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
    printf("Waiting time of processes: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", wt[i]);
    }
    printf("\nThe average waiting time is: %f\n", average(wt, size));
}

int main()
{
    int size;
    printf("Enter the number of processes: ");
    scanf("%d", &size);
    int at[size];
    int bst[size];
    int timeQuantum;
    for (int i = 0; i < size; i++)
    {
        printf("Enter the burst time of %d process : ", i + 1);
        scanf("%d", &bst[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the arrival time of %d process : ", i + 1);
        scanf("%d", &at[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);
    waitingTime(bst, at, size, timeQuantum);
    return 0;
}