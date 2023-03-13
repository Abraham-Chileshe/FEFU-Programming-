#include <stdio.h>
#include <string.h>

int main(){
    FILE *myfile;
    int count = 0;
    char word[50];

    myfile = fopen("input.txt", "r");

    if (myfile == NULL)
        printf("Text file is blank\n");
    else{

        while (fscanf(myfile, "%s", word) != EOF){
            int n = strlen(word);
            for (int i = 1; i < n; i++)
                if (word[i] != word[0]){
                    break;
                }else{
                    if(i==(n-1))
                        count++;
                }
        }

        printf(""
               "\n-----------------------------------------\n"
               "Number of uniform words found = %d"
               "\n-----------------------------------------\n", count);

        fclose(myfile);
    }
    return 0;
}