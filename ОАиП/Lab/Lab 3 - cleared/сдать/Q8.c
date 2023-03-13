#include <stdio.h>

int main() {
     int a, q;
        printf("Enter a and q: ");
        scanf("%d %d", &a, &q);
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
        
        printf("Answer: ");
        for(int i=0; i<size; i++)
            printf("%d", NUM[i]);

    return 0;
}