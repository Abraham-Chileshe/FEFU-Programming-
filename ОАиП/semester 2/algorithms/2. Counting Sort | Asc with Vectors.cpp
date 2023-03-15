#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define open cout << "[ ";
#define close cout << "]"<<std::endl;
#define line cout<<"-----------------------------------------------------------------\n";

void count_sort(std::vector<int> arr, int len) {
    int maxNum = *max_element(arr.begin(), arr.end());
    int minNum = *min_element(arr.begin(), arr.end());
    int _indexRange = (maxNum - minNum) + 1;
    int j = minNum;

    std::vector<int> index_arr;
    std::vector<int> count_arr;
    std::vector<int> SumCount;
    std::vector<int> result_arr;

    //Printing the original input array
    std::cout<<"\nOriginal array: ";
    std::open
    for (int i = 0; i < len; i++) {
        std::cout<<std::fixed<<std::setw(2)<< arr[i] << ", ";
    }
    std::close;
    std::line;


    //Creating a index array from Min, ... , Max;
    std::cout<<"Index Array: ";
    std::open
    for(int i=0; i < _indexRange; i++) {
        index_arr.push_back(j);
        std::cout<<std::fixed<<std::setw(2)<<index_arr[i] << ", ";
        j++;
    }
    std::close;
    std::line;


    std::cout<<"Count Array: ";
    std::open
    for(int i =0; i < _indexRange; i++) {
        //this code check if the element is the index_arr are found in the input array
        // it also checks how many times they appear;
        if (std::find(arr.begin(), arr.end(), index_arr[i]) != arr.end())
            count_arr.push_back(count(arr.begin(), arr.end(), index_arr[i]));
        else
            count_arr.push_back(0); // push_back a zero if index_Arr element is not fount in input arr
        std::cout<<std::fixed<<std::setw(2)<<count_arr[i]<<", ";
    }
    std::close;
    std::line;


    //Printing the SumCount Array;
    std::cout<<"SumCount Arr: ";
    std::open
    int init = count_arr[0];
    for(int i = 0; i<_indexRange; i++){
        if(i != 0)
            init += count_arr[i];

        SumCount.push_back(init);
        std::cout<<std::fixed<<std::setw(2)<<SumCount[i]<<", ";
    }
    std::close;
    std::line;
    std::cout<<"\n\n";


    std::cout<<"Choose Values: ";
    for(int i=0; i < len; i++) {
        std::cout<< arr[i] << ", ";
    }
    std::cout<<std::endl;
    std::line;

    std::cout<<"SumCount Arr: ";
    std::open
    for(int i=0; i < _indexRange; i++) {
        std::cout<<std::fixed<<std::setw(2)<< index_arr[i] << ", ";
    }
    std::close;
    std::line;

    //Final Step
    std::cout<<"Final Posit.: ";
    std::open
    for(int i = 0; i<_indexRange; i++){
        std::cout<<std::fixed<<std::setw(2)<< SumCount[i]<<", ";
    }
    std::close;
    std::line;


    for (int i = 0; i < len; i++) {
        result_arr.push_back(0); //set the number of positions to a zero
    }

    for(int i = 0; i<len; i++){

        auto it = find(index_arr.begin(), index_arr.end(), arr[i]);
        int pos_index = it - index_arr.begin();

        int Fpos = SumCount[pos_index];

        result_arr.at(Fpos-1) = arr[i]; // adding positions to the array
        SumCount[pos_index]--;
    }
    std::cout<<"\n";


    //Final Result
    std::cout<<"Sorted Array ";
    std::open
    for(int i = 0; i<len; i++){
        std::cout<<result_arr[i]<<", ";
    }
    std::close;
    std::line;
    //Final Result;

}

int main(){
    int N, Num;
    std::vector<int> elements;

    std::cout<<"Enter N: ";
    std::cin>>N;

    //Creating a vector array with N elements
    for(int i=0; i<N; i++){
        std::cin>>Num;
        elements.push_back(Num);
    }

    count_sort(elements, N);

    return 0;
}
