#include <iostream>

void gcd(int,int);

int main(){
    int a,b;
    std::cin>>a>>b;
    gcd(a,b);

    return 0;
}

void gcd(int a,int b) {
    int R;
    int steps = 0;
    while ((a % b) > 0)  {
        R = a % b;
        a = b;
        b = R;
        steps += 1;
    }
    std::cout<<b<<" "<<steps;
}