#include <stdio.h>

static int roman_to_integer(char c)
{
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int roman_to_int (char *s){

    int int_num = roman_to_integer(s[0]);

    for (int i = 1; s[i] != '\0'; i++) {

        int prev_num = roman_to_integer(s[i - 1]);
        int cur_num = roman_to_integer(s[i]);

        if (prev_num < cur_num) {
            int_num = int_num - prev_num + (cur_num - prev_num);
        } else {
            int_num += cur_num;
        }
    }
    return int_num;
}
int main(void){
    FILE *in;
    char word[50];

    in = fopen("input.txt", "r");

    while (fscanf(in, "%s", word) != EOF){

        char *str1 = word;
        printf("%s", str1);
        printf(" - %d \n", roman_to_int(str1));
    }

    fclose(in);

    return 0;
}