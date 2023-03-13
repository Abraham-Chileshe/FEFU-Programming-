#include <iostream>

int main(){
    int n,m,ans;
    std::cin>>n>>m;

    ans = ((1 << n) | (1 << m));
    std::cout<< ans;

    return 0;
}