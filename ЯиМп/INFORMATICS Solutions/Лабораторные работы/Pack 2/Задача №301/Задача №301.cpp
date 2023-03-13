#include <iostream>
#include <cmath>

int main() {

    float a, b, c;
    float x1, x2;
    float discriminant;

    std::cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;

    if (discriminant > 0) { // roots are real and different.
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << x1 << " " << x2 << std::endl;
    }

    else if (discriminant == 0) { // roots are real and same
        if(b == 0)
            x1 = b/(2*a);
        else
            x1 = -b/(2*a);
        std::cout << x1 << std::endl;
    }else{}


    return 0;
}