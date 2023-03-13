#include <iostream>

int main(){
    int N;
    float sum = 1;
    float factorial = 1;

    std::cin>>N;

    for(int i = 1; i<=N; i++) {
        factorial *= i;
        sum += (1/factorial);
    }

    std::cout << sum;

    return 0;
}

