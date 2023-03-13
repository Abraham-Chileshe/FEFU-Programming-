#include <iostream>
#include <fstream>

int main(){
    int A,B;
    int X, Y;

    std::ifstream in;
    in.open ("input.txt");
    in>>A>>B;
    in.close();

    for(int x =0; x <= A; x++){
        if((x^(A-x)) == B){
            X = x;
            Y = A - X;
            break;
        }else{
            X = 1;
            Y = 1;
        }
    }

    std::ofstream outs;
    outs.open ("output.txt");
    if(X==1 && Y ==1)
        outs <<1;
    else
        outs <<X <<" "<<Y;

    outs.close();


    return 0;
}