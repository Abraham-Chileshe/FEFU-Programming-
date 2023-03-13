#include <stdio.h>
#include <string.h>


bool allCharactersSame(string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] != s[0])
            return false;

    return true;
}

int main(){
    FILE *myfile;
    int count = 0;
    char word[50];
    char A,B;
    printf("Enter the first and last character:\n ");
    scanf("%c %c",&A, &B);

    myfile = fopen("input.txt", "r");

    if (myfile == NULL)
        printf("Text file is blank\n");
    else{

        while (fscanf(myfile, "%s", word) != EOF){

        }

       printf(""
              "\n-----------------------------------------\n"
              "Number of words found = %d"
              "\n-----------------------------------------\n", count);

        fclose(myfile);
    }
    return 0;
}