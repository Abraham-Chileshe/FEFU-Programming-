#include <stdio.h>

int print_array(int size, int A[size])
{
    for(int i = 0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n")                                    ;
    return 0;
}

int sort(int K,  int A[],  int m)
{
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
    print_array(K, A);
    return 1;
}


int main() {
    int K = 14; int A[14] = {
                             -5, 1, 0, -3, 4,
                             9, 25, 0, 1, 23,
                             19, -17, 14, 22
                            };

    int ex;
    printf("EX: ");
    scanf_s("%d", &ex);
    printf("\n");
    if (ex==1) {
        printf("Ex1\n");
        int proizved = 1, summ = 0;
        for (int i = 0; i < K; ++i) {
            if (A[i] > 0)
                summ += A[i];
            else if (A[i] != 0)
                proizved *= A[i];
        }
        printf("Sum: %d\nProizved: %d", summ, proizved);
    }
    else if(ex==2)
    {printf("\n\nEx2\n");
    int Flag = 0;
    for (int i = 0; i < K - 1; ++i) {
        if (A[i] > A[i + 1]) {
            Flag = 1;
            break;
        }
    }
    if (Flag == 1)
        printf("No");
    else
        printf("Yes");}
    else if(ex==3){
    printf("Ex 3\n");

    int b, count = 0, i1 = -1, i2;
    printf("find d: ");
    scanf_s("%d", &b);
    for (int i = 0; i < K; ++i) {
        if (A[i] == b) {
            count++;
            if (i1 == -1) {
                i1 = i;
            }
            i2 = i;
        }
    }
    if (count == 0)
        printf("No b in {A}");
    else if (count == 1)
        printf("b in A[%d]", i2);
    else
        printf("(%d, %d, %d)", count, i1, i2);}
    else if (ex==4) {
        printf("Ex 4\n");
        int i = 0;
        int count = 0;
        print_array(K, A);
        printf("\n");
        i = 0;
        while (i < K && i + count < K) {
            if (A[i] == 0) {
                if (A[i + count] != 0) {
                    A[i] = A[i + count];
                    A[i + count] = 0;
                    i++;
                } else
                    count++;
            } else
                i++;
        }
        print_array(K, A);}
    else if(ex==5){
        printf("Ex 5\n");

        int m;
        scanf_s("%d", &m);
        sort(K, A, m);}
    else if(ex==6) {
        printf("Ex 6\n");
        for (int i = 0; i < K - 1; i++) {
            for (int j = (K - 1); j > i; j--) {
                if (A[j - 1] > A[j]) {
                    int temp = A[j - 1];
                    A[j - 1] = A[j];
                    A[j] = temp;
                }
            }
        }



        int fin;
        scanf_s("%d", &fin);
        int low, high, middle;
        low = 0;
        high = K - 1;
        int Flag = 0;
        while (low <= high) {
            middle = (low + high) / 2;
            if (fin < A[middle])
                high = middle - 1;
            else if (fin > A[middle])
                low = middle + 1;
            else {
                printf("index: %d", middle);
                Flag = 1;
                break;
            }

        }
        if (Flag == 0) {
            printf("NONE");
        }
    }
    else if(ex==7) {
        printf("Ex 7\n");
        print_array(K, A);
        printf(" --> ");
        for (int i = 0; i < K / 2; i++) {
            int tmp = A[i];
            A[i] = A[K - i - 1];
            A[K - i - 1] = tmp;
        }
        print_array(K, A);
    }
    else if(ex==8) {
        printf("Ex 8\n");
        int a, q;
        scanf_s("%d %d", &a, &q);
        int i = 1;
        int size = 0;
        int a1 = a;
        while (a1 > 0) {
            a1 /= q;
            size++;
        }
        int NUM[size];
        while (a > 0) {
            NUM[size - i] = a % q;
            a /= q;
            i++;
        }
        print_array(size, NUM);

    }
    else if(ex==9) {
        printf("Ex 9\n");
        int b, a, q;
        scanf_s("%d %d %d", &a, &b, &q);
        if (b > a) {
            for (int z = a; z <= b; z++) {
                int perl = z;
                int i = 1;
                int size = 0;
                int a1 = perl;
                while (a1 > 0) {
                    a1 /= q;
                    size++;
                }
                int NUM[size];
                while (perl > 0) {
                    NUM[size - i] = perl % q;
                    perl /= q;
                    i++;
                }
                int Flag = 0;
                for (int j = 0; j < size / 2; j++) {

                    if (NUM[j] != NUM[size - j - 1]) {
                        Flag = 1;
                        break;
                    }
                }
                if (Flag == 0)
                    print_array(size, NUM);


            }
        } else
            printf("No diapazon");
    }
    else if(ex==10) {
        printf("Ex 10\n");
        int M;
        scanf_s("%d", &M);
        if (M >= 2) {
            int tabl[M - 1];
            int j = 0;
            for (int i = 2; i <= M; i++) {
                tabl[j] = i;
                j++;
            }
            for (int i = 0; i < M - 1; i++) {
                if (tabl[i] != 0) {

                    int z = tabl[i];
                    for (j = i + z; j < M; j += z) {
                        tabl[j] = 0;
                    }
                    printf("%d ", z);
                }
            }
        }
    }
    else if(ex==11)
    {
    printf("Ex 11\n");
    int M;
    scanf_s("%d", &M);

    int tabl[M], tabl2[M];
    int j = 0;
    for (int i = 0; i <= M; i++) {
        tabl[i] = i;
        tabl2[i] = i;
    }
    for(int i = 0; i<=M; i++)
    {
        if (tabl[i] != 0)
        {
            int sum = 0, vr = tabl[i];
            if (vr<10)
                tabl2[i+i] = 0;
            else {
                while (vr > 0) {
                    sum += vr % 10;
                    vr /= 10;
                }
                if(sum>10)
                    tabl2[sum] = 0;
            }
        }
    }

    for (int i = 0; i<M; i++)
    {
        if (tabl2[i]!= 0)
            printf("%d ", tabl2[i]);
    }
    }
    return 0;
}