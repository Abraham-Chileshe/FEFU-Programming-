#include <iostream>
#include<String>
#include <fstream>
#include <iomanip>

int isValid(std::string str, int n)
{

    // If first character is invalid
    if (!((str[0] >= 'a' && str[0] <= 'z')
          || (str[0] >= 'A' && str[0] <= 'Z')
          || str[0] == '_'))
        return 0;

    // Traverse the string for the rest of the characters
    for (int i = 1; i < str.length(); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z')
              || (str[i] >= 'A' && str[i] <= 'Z')
              || (str[i] >= '0' && str[i] <= '9')
              || str[i] == '_'))
            return 0;
    }

    // String is a valid identifier
    return 1;
}

int is_digits(std::string& str){
    for (char ch : str) {
        int v = ch; // ASCII Val converted
        if (!(ch >= 48 && ch <= 57)) {
            return 0;
        }
    }

    return 1;
}






int main() {
    std::fstream file;
    std::string stringz, t, q, filename;
    file.open("input.txt");
    

    while (file >> stringz) {
        int n = stringz.length();

        if (isValid(stringz, n))
            std::cout<< stringz <<std::setw(6)<<" - IDENT "<<std::endl;
        else if( is_digits(stringz))
            std::cout<< stringz <<std::setw(6) <<" - CONST"<<std::endl;
        else
            std::cout<< stringz <<std::setw(6)<<" - ERROR"<<std::endl;





    }


    file.close();





    return 0;
}
