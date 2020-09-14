
#include<stdio.h>

int binarySearch(int num,int arr[],int size){
    int l = 0;
    int h = size-1;
    while(l<=h){
        int mid = (l+h)/2;
        if (arr[mid]==num){
            return mid;
        }
        else if (arr[mid]>num)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int size,num;
    FILE *file;
    file = fopen("input.txt","r");

    fscanf(file,"%d",&size);

    int arr[size];
    for(int i = 0;i<size;i++)
        fscanf(file,"%d",&arr[i]);
    fscanf(file,"%d",&num);
    int res = binarySearch(num,arr,size);
    if (res == -1)    printf("not found");
    else    printf("element found at index %d",res);
    fclose(file);
    return 0;
}
