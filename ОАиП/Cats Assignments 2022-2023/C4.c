#include <stdio.h>
#include <math.h>
int main() {
    float X1, X2;
    float Y1, Y2;
    float XP, YP;
    int check = 0;
    int Flag = 1;

    FILE * IN = fopen("input.txt", "r");
    FILE * OUT = fopen("output.txt", "w");

    fscanf(IN, "%f %f", &X1, &Y1);
    fscanf(IN, "%f %f", &X2, &Y2);


    if ((X1 > 0) && (X1 < 9) && (X2 > 0) && (X2 < 9) && (Y1 > 0) && (Y1 < 9) && (Y2 > 0) && (Y2 < 9)) {

        check = (fabs(X1 - X2) == fabs(Y1 - Y2));

        if ((check == 1) && ((fabs(X1 - X2) > 1) && (fabs(Y1 - Y2) > 1))) {//Проверка на диагональность пешек, расстояние больше единицы => можно поставить слона между ними

            if (((X1 < X2) && (Y1 > Y2)) || ((X1 > X2) && (Y1 < Y2)))
                fprintf(OUT, "%d %d", (int)ceil((X1 + X2) / 2), (int)floor((Y1 + Y2) / 2)); //неидеальность шахматной доски => 2 подходящие точки
            else
                fprintf(OUT, "%d %d", (int)ceil((X1 + X2) / 2), (int)ceil((Y1 + Y2) / 2));

        }else if ((check == 1) && (fabs(X1 - X2) <= 1) && (fabs(Y1 - Y2) <= 1))
                fprintf(OUT, "%d", 0);

        else if (check == 0) {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {

                    XP = i;
                    YP = j;
                    check = ((fabs(XP - X1)) == (fabs(YP - Y1))) && ((fabs(XP - X2)) == (fabs(YP - Y2)));

                    if (check == 1) {
                        fprintf(OUT, "%d %d", (int)XP, (int)YP);
                        Flag = 0;
                        break;
                    }
                }
                if (Flag == 0)
                    break;
            }
            if (Flag == 1)
                fprintf(OUT, "%d", 0);
        }
    }else
        fprintf(OUT, "%d", 0);

    return 0;
}