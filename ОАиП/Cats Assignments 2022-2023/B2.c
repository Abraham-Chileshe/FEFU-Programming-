#include <stdio.h>

int main() {
    double eps = 1e-9;
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");

    double x_rect[4];
    double y_rect[4];
    double  x, y;

    fscanf(IN, "%lf %lf %lf %lf %lf %lf", &x_rect[0], &y_rect[0], &x_rect[1], &y_rect[1], &x, &y);
    double x_c = (x_rect[0] + x_rect[1]) / 2;
    double y_c = (y_rect[0] + y_rect[1]) / 2;
    double dist[4];
    double dr = (x_c - x) * (x_c - x) + (y_c - y) * (y_c - y);

    dist[0] = (x_rect[0] - x) * (x_rect[0] - x) + (y_rect[0] - y) * (y_rect[0] - y);
    dist[1] = (x_rect[0] - x) * (x_rect[0] - x) + (y_rect[1] - y) * (y_rect[1] - y);
    dist[2] = (x_rect[1] - x) * (x_rect[1] - x) + (y_rect[0] - y) * (y_rect[0] - y);
    dist[3] = (x_rect[1] - x) * (x_rect[1] - x) + (y_rect[1] - y) * (y_rect[1] - y);


    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            if(dist[i] < dist[j]){
                double tmp = dist[i];
                dist[i] = dist[j];
                dist[j] = tmp;
            }
        }
    }

    if (dist[0] >= dr) {
        fprintf(OUT, "CENTER");
    }else{
        fprintf(OUT, "CORNER");
    }
    return 0;
}