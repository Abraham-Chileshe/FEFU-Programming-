#include <stdio.h>

int main() {
    FILE *input;
    input = fopen("input.txt", "r");
    int a;
    scanf("%d", &a);
    fseek(input, 0L, SEEK_END);
    int size = ftell(input) / a;
    char str[size][a], sim;
    fclose(input);
    
    input = fopen("input.txt", "r");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < a; j++) {
            fscanf(input, "%c", &sim);
            str[i][j] = sim;
        }
        for (int ij = 0; ij < a - 1; ij++) {
            for (int j = (a - 1); j > ij; j--) {
                if (str[i][j - 1] > str[i][j]) {

                    char temp = str[i][j - 1];
                    str[i][j - 1] = str[i][j];
                    str[i][j] = temp;
                }
            }
        }

    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < a; j++)
            printf("%c", str[i][j]);
        printf(" ");
    }

    return 0;
}
