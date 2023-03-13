#include <iostream>
#include <cmath>

int main(){
    int n;
    double x;
    std::cin >> n >> x;


    double power = 1;
    double sum = 1;
    double factorial = 1;


    for(int i = 1; i<=n; i++) {

        power *=x;
        factorial *= i;
        sum += (power/factorial);
    }

    std::cout<<sum;

    return 0;
}