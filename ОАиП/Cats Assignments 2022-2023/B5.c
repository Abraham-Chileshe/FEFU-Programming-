#include <stdio.h>


int main() {
    float num;
    FILE * IN = fopen("input.txt","r");
    FILE * OUT = fopen("output.txt", "w");


    fscanf(IN, "%f", &num);
    int *l= (int *) &num;
    int BinaryOrder = ((*l >> 23) & 255) - 127;

    if (num == 0)
        BinaryOrder = 0;
    else if (BinaryOrder < -126)
        BinaryOrder = -126;


    fprintf(OUT, "%d", BinaryOrder);


    fclose(IN);
    fclose(OUT);

    return 0;
}