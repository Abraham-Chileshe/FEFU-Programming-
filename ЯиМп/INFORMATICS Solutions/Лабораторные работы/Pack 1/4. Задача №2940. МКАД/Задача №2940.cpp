#include <iostream>

int main(){
    int v,t;
    std::cin>>v>>t;

    int step;

    if(v < 0)
        step = ((109+v)*t)%109;
    else
        step = (v*t)%109;

    std::cout<<step;

    return 0;
}