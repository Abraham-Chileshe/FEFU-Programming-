#include <stdio.h>
int main()
{
    FILE *myfile;
    int n1,n2;
    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d %d", &n1, &n2);
    fclose(myfile);

    int l1 = n1;
    int l2 = n2;

    while (n1 != n2){
        // if num1 is greater than num2, returns the num1.
        if (n1 > n2)
            n1 = n1 - n2;
        else
            n2 = n2 - n1;
    }

    int lcm = (l1 * l2) / n2;

    myfile = fopen("output.txt", "w");
    fprintf(myfile, "%d %d", n2, lcm);
    fclose(myfile);

    return 0;
}