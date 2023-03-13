#include <iostream>
#include <cmath>

int main(){
    float P;
    int X, Y, K;
    std::cin>>P>>X>>Y>>K;

    int sy = 100 * X + Y;  // Сумма только в копейках

    for(int i = 0; i<K; i++)
        sy += sy * P / 100;

    std::cout << floor( sy / 100) << " " << sy % 100;

    return 0;

}