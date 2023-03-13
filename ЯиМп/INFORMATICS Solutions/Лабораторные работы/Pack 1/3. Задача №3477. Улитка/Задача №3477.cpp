#include <iostream>

int main(){
    int h,a,b;
    std::cin>>h>>a>>b;

    int day = (h - 2 * b + a - 1) / (a-b);
    std::cout<<day;

    return 0;
}