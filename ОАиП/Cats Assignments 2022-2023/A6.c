#include <stdio.h>

void CubeColor (FILE * result, int cnt_cube){

    for (int i = 0; i < cnt_cube; i++){

        for (int j = 0; j < cnt_cube; j++){
            for (int z = 0; z < cnt_cube; z++)
                fprintf(result, "%d ", 1 + (i + j + z) % cnt_cube);
            fprintf(result, "\n");
        }

    }
}


int main() {
    int cnt_cube;
    FILE * In = fopen("input.txt", "r");
    FILE * result = fopen("output.txt", "w");

    fscanf(In, "%d", &cnt_cube);
    CubeColor(result, cnt_cube);


    fclose(result);
    fclose(In);
}
