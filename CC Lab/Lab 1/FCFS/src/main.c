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

void waitingTime(int bst[], int at[], int size)
{
    int wt[size];
    wt[0] = 0;
    for (int i = 1; i < size; i++)
    {
        wt[i] = bst[i - 1] + wt[i - 1];
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
    waitingTime(bst, at, size);
    return 0;
}