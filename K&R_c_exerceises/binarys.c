#include <stdio.h>


int find(int x, int arr[], int length);

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("%d\n", find(2, arr, 8));
    return 0;
}

int find(int x, int arr[], int length)
{
    int bottom, mid, top;
    bottom = 0;
    top = length;
    while(top > bottom){
        mid = (bottom + top) / 2;
        if(x < arr[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    }
    return (arr[mid] == x) ? mid : -1;
}
