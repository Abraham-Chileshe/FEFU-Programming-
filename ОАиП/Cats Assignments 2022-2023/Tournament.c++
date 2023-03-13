#include <stdio.h>
#include <math.h>


int main(){
    FILE *in;
    FILE *out;

    int N;
    in = fopen("input.txt", "r");
    fscanf(in, "%d", &N);

    int x[N];
    int y[N];

    int cx, cy;

    for(int i =0; i<N; i++) {
        fscanf(in, "%d %d", &cx, &cy);
        x[i] = cx;
        y[i] = cy;
    }
    fclose(in);
    int d;
    int max = 0;

    //x1 x2  are equal them vertical
    //y1 y2 sre equal then horizontal

    int yy1,yy2;



    for(int i = 0; i<N; i++) {
        for(int j= 0; j<N; j++){

            if((x[i]==x[j]) && (i != j) && (i < j)){

                yy1 = y[i];
                yy2 = y[j];


                d = sqrt(pow((x[i] - x[j]), 2) + pow((yy1 - yy2), 2));


                if(max<d){
                    max =d;
                }

            }

        }
    }


    int xx1,xx2;
    //vertical
    for(int i = 0; i<N; i++) {
        for(int j= 0; j<N; j++){

            if((y[i]==y[j]) && (i != j) && (i < j)){

                xx1 = x[i];
                xx2 = x[j];

                d = sqrt(pow((y[i] - y[j]), 2) + pow((xx1 - xx2), 2));

                if(max<d){
                    max =d;
                }


            }

        }
    }


    out = fopen("output.txt", "w");
    fprintf(in, "%d", max);
    fclose(out);
    //vertical






    return 0;
}