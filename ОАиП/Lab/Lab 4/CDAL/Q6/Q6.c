#include <stdio.h>
#include <string.h>

void revstr(char *str1){
    int i, len, temp;
    len = strlen(str1);

    for (i = 0; i < len/2; i++){
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

int main(){

    FILE *in;
    char word[100];

    in = fopen("input.txt", "r");

    while (fscanf(in, "%s", word) != EOF){
        printf ("%s", word);
        revstr(word);
        printf (" - %s\n", word);
    }

    fclose(in);
    
}