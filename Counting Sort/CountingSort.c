/*
 * C Program for counting sort
 */
#include <stdio.h>

/*  Counting sort function  */

int count(){
    int temp;
    int count = 0;
    FILE *file = fopen("input.txt","r");
    if(file == NULL){
        printf("Could not open specified file");
        return -1;
    }
    while(fscanf(file,"%d",&temp)==1){
        count++;
    }
    return count;
}
void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[n], C[k];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    // creating file pointer to work with files
    FILE *fileOut;

    // opening file in writing mode
    fileOut = fopen("output.txt", "w");
    fprintf(fileOut, "No of Elements are %d\n", n);
    fprintf(fileOut, "\nList of elements are\n");
    for (int i = 1; i <=n; ++i){
        fprintf(fileOut, "%d ", B[i]);
    }
    fclose(fileOut);
}
/*  End of counting_sort()  */

/*  The main() begins  */
int main()
{
    int k = 0, i;
    int a = count();
    printf("%d",a);
    int A[a];
    FILE *file;
    file = fopen("input.txt","r");
    for(int i = 1;i<=a;i++){
        fscanf(file,"%d",&A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }
    fclose(file);
    counting_sort(A, k, a);
    printf("\n");
    return 0;


}


