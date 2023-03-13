#include <iostream>


int main() {
    int array[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int month, day;
    int flag = 0;
    int total;
    std::cin>>day>>month;

    int j = (month-1); // accessing day in array
    int sum = 0;
    for(int i = j; i<12; i++){
        sum += array[i];
    }
    total = sum - day;

    for(int i = 1; i<= total; i++){
        if(flag == 0)
            flag = 1;
        else
            flag = 0;
    }

    if(flag == 0)
        std::cout << 1 << std::endl;
    else
        std::cout << 2 << std::endl;
    return 0;
}
