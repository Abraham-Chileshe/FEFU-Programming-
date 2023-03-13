#include <stdio.h>
#include <string.h>

int main(){
    char str[6];
    char out[6];
    char ch = '*';
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");

    fscanf(IN, "%s", str);
    strcpy(out, str);
    for (int i = 0; i < strlen(str); i++){

        if (str[i] == '<'){
            if (ch == '*' || ch == '+')
                ch = '+';
            else
                ch = '?';
        }

        else if (str[i] == '>'){
            if (ch == '*' || ch == '-')
                ch = '-';
            else
                ch = '?';
        }
        out[i] = ch;
    }

    fprintf(OUT, "%s", out);
}