#include <iostream>
#include <math.h>
#define line cout<<"-------------------------------------------------\n";


double g(double x);
double h(double x);
double F(double x){
    return g(x) - h(x);
}

int variant;
float y, x, a;
float eps = 0.0001;
float delta = 2 * eps;


int main(){
    std::cout<<"Enter variant Number: ";
    std::cin>>variant;

    x = -5; //lower Limit
    y = 5;  //Upper Limit
    a = x;

    std::line;
    while(x <= y){
        x += delta;
        if (x - a >= 0.5){
            a += 0.5;
        }
        if(F(x)*F(x+delta) < 0){
            std::cout << "Root intervals ["<< a << " ; " << a + 0.5 <<"]" << std::endl;
            std::cout << "Root : " << round((x + eps) * 1000) / 1000 <<std::endl;
            std::line;
        }
    }

    return 0;
}



double g(double x) {
    double y;

    switch(variant){
        case 1:  y = pow(x, 3) - 8 * x + 1; break;
        case 2:  y = pow(x, 3) - 8 * x + 1; break;
        case 3:  y = pow(x, 3) - 8 * x + 1; break;
        case 4:  y = pow(x, 3) - 8 * x + 1; break;
        case 5:  y = pow(x, 3) - 8 * x + 1; break;
            //----------------------------------------------------------------
        case 6:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 7:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 8:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 9:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 10: y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
            //----------------------------------------------------------------
        case 11: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 12: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 20; break;
        case 13: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 14: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 15: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 20; break;
            //----------------------------------------------------------------
        case 16 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 17 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 18 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 19 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 20 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;

        default: NAN;
    }
    return y;
}
double h(double x) {
    double y;
    switch(variant){
        case 1: y = 5 * sin(x); break;
        case 2: y = -2 * sin(x) - 10 * cos(x); break;
        case 3: y = -12 * sin(x) - 10 * cos(x); break;
        case 4: y = 5 * sin(x) + 12 * cos(x); break;
        case 5: y = -5 * sin(x) + 12 * cos(x); break;
            //--------------------------------------------------------------
        case 6: y = -2 * sin(x) - 15 * cos(x); break;
        case 7: y = -2 * sin(x) + 5 * cos(x); break;
        case 8: y = -12 * sin(x) + 8 * cos(x); break;
        case 9: y = 5 * sin(x) + 12 * cos(x); break;
        case 10: y = -5 * sin(x) + 12 * cos(x); break;
            //---------------------------------------------------------------
        case 11: y = -cos(x); break;
        case 12: y = -8 * sin(x) + 8 * cos(x); break;
        case 13: y = -5 * sin(x) + 5 * cos(x); break;
        case 14: y = -10 * sin(x) + 10 * cos(x); break;
        case 15: y = -18 * sin(x) + 25 * cos(x); break;
            //---------------------------------------------------------------
        case 16: y = -sin(x) - cos(x); break;
        case 17: y = -sin(x) - 15 * cos(x); break;
        case 18: y = -10 * sin(x) - 20 * cos(x); break;
        case 19: y = -10 * sin(x) + 10 * cos(x); break;
        case 20: y = -18 * sin(x) + 25 * cos(x); break;
        default: NAN;
    }
    return y;
}
