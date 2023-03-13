#include <stdio.h>

int sort(int K,  int A[],  int m){
    //BUBBLE SORT
    if (m == 1)
    {
        for (int i = 0; i < K - 1; i++)
        {
            for (int j = (K - 1); j > i; j--)
            {
                if (A[j - 1] > A[j])
                {
                    int temp = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }
    }
    else if (m == -1)
    {
        for (int i = 0; i < K - 1; i++)
        {
            for (int j = (K - 1); j > i; j--)
            {
                if (A[j - 1] < A[j])
                {
                    int temp = A[j];
                    A[j] = A[j - 1];
                    A[j-1] = temp;
                }
            }
        }
    }
        //BUBBLE SORT

        //SELECTION SORT
    else if (m == 2)
    {
        for (int i = 0; i < K; i++)
        {
            int min = i;
            for (int j = i + 1; j < K; j++)
                if (A[min] > A[j])
                    min = j;
            int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }
    }
    else if (m==-2)
    {
        for (int i = 0; i < K; i++)
        {
            int min = i;
            for (int j = i + 1; j < K; j++)
                if (A[min] < A[j])
                    min = j;
            int tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }
    }
    //SELECTION SORT
    for(int i = 0; i<K; i++)
        printf("%d, ", A[i]);

    return 1;
}


int main() {
    int N,m;
    int count = 0;

    printf("Enter size of Array: ");
    scanf("%d", &N);
    int A[N];

    printf("Enter elements: ");
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);

    printf("Enter m: ");
    scanf("%d", &m);
    sort(N, A, m);

    return 0;
}