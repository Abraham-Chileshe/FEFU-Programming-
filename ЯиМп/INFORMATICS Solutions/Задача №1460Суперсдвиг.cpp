#include <iostream>

int main() {
    int N, k;
    int temp;

    std::cin >> N;
    int a[N];

    for (int i = 0; i < N; i++)
        std::cin >> a[i];

    std::cin >> k;

    /* shifting array elements */
    for (int i = 0; i < k; i++){
        temp = a[N - 1]; //6
        for (int i = N - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }

     for(int i=0; i<N; i++)
        std::cout<<a[i]<<" ";

     return 0;
}