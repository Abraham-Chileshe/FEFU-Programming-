#include <iostream>

int main(){
    unsigned long n,i;
    std::cin>>n>>i;

    n = n & ~ (1 << i);
    std::cout<<n;

    return 0;
}