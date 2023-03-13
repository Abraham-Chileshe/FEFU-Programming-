#include <stdio.h>
#define ABS(a) (a < 0 ? (-a) : (a))

int main() {
    FILE * IN  = fopen("input.txt", "r");
    FILE * OUT = fopen("output.txt", "w");

    int N, M;
    int CurrentOfN = 0;
    int CurrentOfM = 0;
    int NComplen = 0;
    int mCompLen = 0;
    int tmpsum = 0;

    int StringOfN[2][10000] = {};
    int StringOfM[10000] = {};

    char m_prev = -1;
    char in;

    fscanf(IN, "%d %d\n", &N, &M);

    for(int i = 0; i < N; i++) {
        fscanf(IN, "%c", &in);
        if(in == '0')
            ++CurrentOfN;
        else {
            if(CurrentOfN)
                StringOfN[0][NComplen++] = -CurrentOfN;

            StringOfN[0][NComplen++] = 1;
            CurrentOfN = 0;
        }
    }

    if(in == '0')
        StringOfN[0][NComplen++] = -CurrentOfN;

    fscanf(IN, "\n");

    for(int j = 0; j < M; j++) {
        fscanf(IN, "%c", &in);
        if(in == m_prev)
            ++CurrentOfM;
        else{
            if(CurrentOfM)
                StringOfM[mCompLen++] = CurrentOfM * ((m_prev == 'b') ? 1 : -1);

            CurrentOfM = 1;
            m_prev = in;
        }
    }

    StringOfM[mCompLen++] = CurrentOfM * ((m_prev == 'b') ? 1 : -1);

    if(StringOfM[0] < 0) {
        for(int i = 0; tmpsum + ABS(StringOfN[0][i]) <= -StringOfM[0] && i < NComplen; i++) {
            tmpsum += ABS(StringOfN[0][i]);
            StringOfN[1][i] = 1;
        }
    } else
        for(int i = 0; ++tmpsum <= StringOfM[0] && i < NComplen && StringOfN[0][i] == 1; StringOfN[1][i++] = 1);
    

    for(int j = 1; j < mCompLen; j++) {
        for(int i = NComplen - 1; i >= 0; i--) {
            if(StringOfN[1][i]) {
                tmpsum = 0;
                if(StringOfM[j] < 0) {
                    for(int i2 = i + 1; (tmpsum + ABS(StringOfN[0][i2]) <= -StringOfM[j]) && i2 < NComplen; i2++) {
                        tmpsum += ABS(StringOfN[0][i2]);
                        StringOfN[1][i2] = 1;
                    }
                } else 
                    for (int i2 = i + 1; ++tmpsum <= StringOfM[j] && StringOfN[0][i2] == 1; StringOfN[1][i2++] = 1);
                StringOfN[1][i] = 0;
            }
        }
    }

    fprintf(OUT, "%c", StringOfN[1][NComplen - 1] ? 'Y' : 'N');
    
    return 0;
}