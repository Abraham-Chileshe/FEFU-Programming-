#include <stdio.h>

int main() {
    int a, n;
    int result = 1;

    printf("a: ");
    scanf("%d", &a);

    printf("n:");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        result *= a;
    }

    printf("%d", result);

    return 0;
}
