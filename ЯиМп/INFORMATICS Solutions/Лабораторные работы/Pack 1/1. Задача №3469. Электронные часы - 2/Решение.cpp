#include <iostream>
#include <iomanip>

void ConvertSectoDay(int n){
    n = n % (24 * 3600);
    int hour = n / 3600;

    n %= 3600;
    int minutes = n / 60 ;

    n %= 60;
    int seconds = n;

    std::cout << hour << ":"<<std::setfill('0') << std::setw(2) << minutes << ":"<<std::setfill('0') << std::setw(2) <<seconds;
}

int main(){
    int n;
    std::cin>>n;
    ConvertSectoDay(n);
    return 0;
}
