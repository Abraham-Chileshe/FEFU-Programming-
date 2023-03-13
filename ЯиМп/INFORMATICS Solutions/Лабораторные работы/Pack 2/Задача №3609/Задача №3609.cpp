#include <iostream>

int main()
{
    double number;
    int result;
    std::cin>>number;
    result = abs(static_cast<int>(number*10))%10;

    std::cout<<result;

}