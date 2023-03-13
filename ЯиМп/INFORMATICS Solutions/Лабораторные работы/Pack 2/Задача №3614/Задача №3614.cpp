#include <iostream>

int main(){
    float a, h;
    int hours;
    int minutes;
    int seconds;

    std::cin>>a;
    h = 30;

    hours = a / h;
    minutes = (a / h * 60);
    minutes %= 60;
    seconds = a / h * 3600;
    seconds %= 60;

    std::cout<<hours<<" "<<minutes<<" "<< seconds<<std::endl;


    return 0;
}