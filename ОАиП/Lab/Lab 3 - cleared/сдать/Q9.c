#include <stdio.h>

int main() {
    int a,b;
    int q;
    
    printf("Enter a, b and q: ");
    scanf("%d %d %d", &a, &b, &q);
    
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
            if (Flag == 0){
                for(int i = 0; i<size; i++)
                    printf("%d", NUM[i]);
                    printf("\n");
            }
        }
    } else
        printf("Incorrect Range");
    
   
    return 0;
}