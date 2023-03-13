#include <stdio.h>

int main() {
    FILE *input;


    char a='f';
    int scobs = 0, znac=0, num=0, flag =1;
    input = fopen("input.txt", "r");

    while (!feof(input)) {
        fscanf(input, "%c", &a);

        if(a=='\n')
            break;
        if(scobs<0 || (znac>1&&scobs==0 && num<=0)) {
            flag = 0;
            break;
        }
        if(a=='(') {
            scobs++;
        }
        else if(a==')') {
            scobs--;
        }
        else if((a == '*' || a == '+' || a=='/' || a=='-'))
        {
            znac++;
            num = 0;
        }
        else if((a == '1' || a == '2' || a=='3' || a=='4'|| a == '5' || a=='6' || a=='7'|| a == '8' || a=='9' || a=='0') && znac==0)
            num++;
        else if((a == '1' || a == '2' || a=='3' || a=='4'|| a == '5' || a=='6' || a=='7'|| a == '8' || a=='9' || a=='0') && znac>0)
        {
            num++;
            znac--;
        }
        else
        {flag = 0;
            break;}


    }
    fclose(input);

    if(scobs!=0 || znac>2)
        flag = 0;

    if(flag==1)
        printf("RIGHT");
    else
        printf("WRONG");


    return 0;
}
