#include <iostream>
#include <vector>
#include <algorithm>
#define open cout<<"[ ";
#define close cout<<"] ";

int main(){
    int N, Num;
    int minNum, maxNum;
    std::cout<<"Enter N";
    std::cin>>N;

    std::vector<int> arr;

    for(int i=0; i<N; i++) {
        std::cin>>Num;
        arr.push_back(Num);
    }

//Selection Sort | Assending Order
    std::cout<<"Assending Order: ";
    std::open;
    for(int i = 0; i<N; i++) {
        minNum = i;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[minNum]) {
                minNum = j;
            }
        }

        int temp = arr[minNum];
        arr[minNum] = arr[i];
        arr[i] = temp;

        std::cout << arr[i] << ", ";
    }
    std::close;
    std::cout<<"\n";
    //-------------------------------------

    int numComparisons = 0;
    int numExchanges = 0;
    //Selection Sort | Assending Order
    std::cout<<"Discending Order: ";
    std::open;
    for(int i = 0; i<N; i++) {
        maxNum = i;

        for (int j = i + 1; j < N; j++) {
            if (arr[j] > arr[maxNum]) {
                maxNum = j;
            }
            numComparisons++;
        }

        int temp = arr[maxNum];
        arr[maxNum] = arr[i];
        arr[i] = temp;
        numExchanges++;

        std::cout << arr[i] << ", ";
    }
    std::close;

    std::cout<<"\n\nComparisons: "<<numComparisons<<std::endl;
    std::cout<<"Exchange: "<<numExchanges;
    //Selection Sort

}
