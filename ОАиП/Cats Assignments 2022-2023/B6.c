#include <stdio.h>
#include <math.h>
int main()
{
    FILE * myfile;
    int x,k;

    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d" ,&x);
    fscanf(myfile, "%d" ,&k);
    fclose(myfile);

    if(k > 300 || k < 0)
        return 0;

    if(x > 2*pow(10,9) || x < 0)
        return 0;

    int binaryNum[32];

    int i= 0;
    while (x > 0) {
        binaryNum[i] = x % 2;
        x /= 2;
        i++; //getting array size
    }

    myfile = fopen("output.txt", "w");
    if(k > 32)
        fprintf(myfile, "%d", 0);
    else
        fprintf(myfile, "%d", binaryNum[k]);


    fclose(myfile);


    return 0;
}