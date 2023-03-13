#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef long long ll;

// Function to calculate the modulus
void modBigNumber(std::string, std::string);

int main(){
    std::string num;
    std::string m;
    std::ifstream myfile ("input.txt");
    if (myfile.is_open()){
        getline(myfile,num);
        getline(myfile,m);

        myfile.close();
    }


    modBigNumber(num, m);
    return 0;
}

std::string removeZero(std::string str)
{
    // Count leading zeros
    int i = 0;
    while (str[i] == '0')
        i++;

    // The erase function removes i characters
    // from given index (0 here)
    str.erase(0, i);

    return str;
}

void modBigNumber(std::string num, std::string m){
// Store the modulus of big number


    std::vector<int> vec;
    ll mod = 0;
    ll mod2 = 0;

    int digitm;
    for (int i = 0; i < m.size(); i++) {

        digitm = m[i] - '0';
        mod2 = mod2* 10 + digitm;

    }

    std::string str_quo = "";

    // Do step by step division
    for (int i = 0; i < num.size(); i++) {

        int digit = num[i] - '0';
        mod = mod * 10 + digit;   // Update modulo by concatenating
        int quo = mod / mod2;  // Update quotient
        str_quo += std::to_string(quo);
        mod = mod % mod2; // Update mod for next iteration.
    }


    std::ofstream myfile;
    myfile.open ("output.txt");


    str_quo= removeZero(str_quo);
    myfile<<str_quo;
    myfile << "\n" << mod << "\n";
    myfile.close();



}