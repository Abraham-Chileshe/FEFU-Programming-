#include <stdio.h>

int main(){
    FILE * myfile;
    int A,C;
    int B = 0;
    int count = 0;
    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d" ,&A);
    fclose(myfile);

    int n = A;

    while (n != 0){
        n /= 10;
        count++;
    }

    if(count!=0){
        int a[count];
        count = 0;
        n = A;

        while (n != 0){
            a[count] = n % 10;
            n /= 10;
            count++;
        }
        int t = 0;
        // iterates the array elements
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (a[i] < a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }

        for (int i = 0; i < count - 1; i++) {
            B += a[i];
            B *=10;
            if(i == (count - 2))
                B /=10;
        }
        A = a[count-1];

        myfile = fopen("output.txt", "w");
        fprintf(myfile, "%d\n%d", B,A);

    }



    return 0;
}