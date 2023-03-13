#include <stdio.h>

int main(){
    FILE * file;
    int k; //the value
    int Nk = 0; //number of k

    //Reading from File
    file = fopen("input.txt", "r");
    fscanf(file, "%d" ,&k);
    fclose(file);
    //-------

    for(int i = 1; i <= k; ++i){
        int X = 0;
        int Z = i;

        while (Z > 0) {
            X = X * 10 + Z % 10;
            Z = Z/10;
        }
        if( i + X == k)
            Nk++;
    }

    //Reading results from Text File
    file = fopen("output.txt", "w");
    fprintf(file, "%d", Nk);
    //--------------
    return 0;
}