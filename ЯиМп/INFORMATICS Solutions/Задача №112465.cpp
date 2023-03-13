#include <iostream>
#include <string>
#include <fstream>


std::string longDivision(std::string, long long);
int calcRem(std::string, long long);

int main()
{
    std::ifstream inFile;
    std::ofstream myfile;
    std::string A;
    long long B;

    inFile.open("input.txt");
    inFile >>A>>B;
    inFile.close();

    if ((A.size() > 10000) ) {
    }else{
        myfile.open ("output.txt");
        myfile << longDivision(A,B)<<"\n"<<calcRem(A,B);
        myfile.close();
    }

    return 0;
}

std::string longDivision(std::string number, long long divisor){
    std::string ans;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

int calcRem(std::string num, long long R){
    long long currDigit, rem = 0;
    for (int i = 0; i < num.length(); i++) {
        currDigit = rem * 10 + (num[i] - '0');
        rem = currDigit % R;
    }
    return rem;
}