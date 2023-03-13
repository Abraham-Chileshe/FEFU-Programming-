#include<stdio.h>

int main(){
    int size;
    int large,small;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);

    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    large = small = arr[0];

    for(int i=1;i<size;++i)
    {
        if(arr[i]>large)
            large=arr[i];

        if(arr[i]<small)
            small=arr[i];
    }

    printf("\nThe smallest element is %d\n",small);
    printf("\nThe largest element is %d\n",large);

    return 0;

}





