#include <stdio.h>

int count()
{
    int temp;
    int count = 0;
    FILE *file = fopen("input.txt","r");
    if(file == NULL)
    {
        printf("Could not open specified file");
        return -1;
    }
    while(fscanf(file,"%d",&temp)==1)
    {
        count++;
    }
    return count;
}

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    FILE *fileOut;

    // opening file in writing mode
    fileOut = fopen("output.txt", "w");

    fprintf(fileOut, "No of objects are %d\n", n);



    fprintf(fileOut, "\nResult :- \n");
    for (i = 0; i < n; i++){
        fprintf(fileOut, "%f\t", weight[i]);
    }

    fprintf(fileOut, "\n");

    for (i = 0; i < n; i++){
        fprintf(fileOut, "%f\t", x[i]);
    }

    fprintf(fileOut, "\n\nMaximum profit is:- %f", tp);

}

int main()
{
    int num = count()/2;
    float weight[num], profit[num], capacity;
    int i, j;
    float ratio[num], temp;

    FILE *file;
    file = fopen("input.txt","r");

    fscanf(file, "%f", &capacity);

    for (i = 0; i < num; i++)
    {
        fscanf(file, "%f %f", &weight[i], &profit[i]);
    }



    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    return(0);
}
