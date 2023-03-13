#include <iostream>
#include <string.h>
#include <math.h>

//variables - переменные
long int p, q; //two prime value inputs
long int n, phi; // n = p*q || phi = (p-1)*(q-1)
long int e[100], d[100]; // 1 < e < phi(n) and gcd(e,phi(n)) = 1  ||  d = e - 1 (mod phi(n))
long int temp[100], m[100], en[100];
long int i,j;
long int flag; // return result for isprime function
char msg[100]; // Message to be encrypted
//-----------------------

//Function declaration - объявление переменных
int prime(long int); // prime check
void ce(); //calulating e
long int cd(long int); //calulating d
void encrypt(); //encrypting
//--------------------------------

int main(){

    //input first input and check if it is prime
    std::cout << "\nEnter the first prime number:";
    std::cin >> p;
    if (prime(p) == 0){
        std::cout << "-----------------------------\nWrong Input\n";  exit(1);
    }
    //----------------------------------

    //input second input and check if it is prime
    // second input should also not be equal to first input
    std::cout << "Enter the second prime number:";
    std::cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q){
        std::cout << "-----------------------------\nWrong Input\n";  exit(1);
    }
    //------------------------------------------

    //Getting the message to be encrypted.
    std::cout << "--------------------------------\nEnter message:";
    fflush(stdin); //used to immediately flush out the contents of an output stream
    std::cin >> msg;

    for (i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i]; //input message as single characters in char mgs[100] array;

    //initialization of declared variables
    n = p * q;
    phi = (p - 1) * (q - 1);
    ce();
    encrypt();
    /*
    std::cout << "\nPossible Values of e and d are:\n";
    for (i = 0; i < j - 1; i++)
        std::cout << e[i] << "\t" << d[i] << "\n";
    */

    return 0;
}



//Function initialization
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
void ce(){
    int k = 0;
    for (i = 2; i < phi; i++){

        if (phi % i == 0)
            continue;
        flag = prime(i);

        if (flag == 1 && i != p && i != q){
            e[k] = i;
            flag = cd(e[k]);

            if (flag > 0){
                d[k] = flag;
                k++;
            }

            if (k == 99)
                break;
        }
    }
}
long int cd(long int x){
    long int k = 1;
    while (1)
    {
        k = k + phi;
        if (k % x == 0)
            return (k / x);
    }
}
void encrypt(){
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    std::cout << "---------------------------------------\nThe Encrypted Message is: ";
    for (i = 0; en[i] != -1; i++)
        printf("%i", en[i]);
}
