#include <iostream>
#include <string>

int main(){
    std::string A;
    std::string B;
    std::cin>>A>>B;

    if(A.length() == B.length()){
        int count = 0;
        for(int i=0; i<A.length(); ++i){
            if(A.at(i) != B.at(i))
                count++;
        }
        std::cout<<count;

    }


    return 0;
}