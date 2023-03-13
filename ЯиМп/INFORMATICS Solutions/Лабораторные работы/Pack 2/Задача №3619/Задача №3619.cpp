#include <iostream>
#include <cmath>

int main() {

    float a, b, c;
    float x1, x2;
    float discriminant;

    std::cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;

    if (discriminant > 0) {  // Two solutions
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);

        if(x1 > x2){
            int temp = x2;
            x2 = x1;
            x1 = temp;
        }
        std::cout << "2 " << x1 << " " << x2 << std::endl;
    }

    else if (discriminant == 0) { // One solution
        if(b == 0)
            x1 = b/(2*a);
        else
            x1 = -b/(2*a);
        std::cout << "1 "<< x1 << std::endl;
    }

    else if (discriminant < 0){
        std::cout<<"0"; //No solutions
    }
    else {
        std::cout<<"3";  // Infinite Solutions
    }

    return 0;
}