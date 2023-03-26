/*
 * Code by Abraham Chileshe
 * Ploting Equations
 * Using graphics.h library
 */

#include <graphics.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

//function declaration
    void bisection(double a, double b, double eps);
    double func(double x);
    double func2(double x);
    double overal(double x);
    std::vector<float> answers;
//----------------------

// trapezoidal rule to calculate the area under the curve
double trapz(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (overal(a) + overal(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += overal(x);
    }
    return abs(sum * h);
}
//----------------------

int main() {
    initwindow(800, 800);
    setbkcolor(15); //white background
    cleardevice();
    
    // set the coordinate system
    setcolor(BLACK);
    setlinestyle(SOLID_LINE, 0, 1);
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);  // X - axis
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());  // Y - axis
    
    // Labelling the axis
    outtextxy(getmaxx() / 2 + 5, getmaxy() / 2 + 5, const_cast<char*>("O"));
    outtextxy(getmaxx() - 15, getmaxy() / 2 + 5, const_cast<char*>("X"));
    outtextxy(getmaxx() / 2 + 5, 5, const_cast<char*>("Y"));
    // ---------------
    
    // label values on the x-axis
    for (int i = -7; i <= 7; i++) {
        int x = getmaxx() / 2 + i * 50;
        if (i != 0) {
            line(x, getmaxy() / 2 - 5, x, getmaxy() / 2 + 5);
            char label[4];
            sprintf(label, "%d", i);
            outtextxy(x - 3, getmaxy() / 2 + 10, label);
        }
    }
    
    // label values on the y-axis
    for (int i = -7; i <= 7; i++) {
        int y = getmaxy() / 2 - i * 50;
        if (i != 0) {
            line(getmaxx() / 2 - 5, y, getmaxx() / 2 + 5, y);
            char label[4];
            sprintf(label, "%d", i);
            outtextxy(getmaxx() / 2 + 10, y + 2, label);
        }
    }
    
    // plot the first graph y = func()
    double x, y, scale = 36;
    for (x = -5.0; x <= 5.0; x += 0.01) {
        y = func(x);
        int px = getmaxx() / 2 + x * scale;
        int py = getmaxy() / 2 - y * scale;

        // Draw the line using multiple putpixel() calls that are slightly offset
        for (int i = 0; i < 3; i++) {
            putpixel(px + i, py, BLUE);
        }
    }
    //-------------------
    
    // plot the second graph y = func()
    for (x = -6.0; x <= 7.0; x += 0.01) {
        y = func2(x);
        int px = getmaxx() / 2 + x * scale;
        int py = getmaxy() / 2 - y * scale;

        // Draw the line using multiple putpixel() calls that are slightly offset
        for (int i = 0; i < 2; i++) {
            putpixel(px + i, py, RED);
        }
    }
    //-------------------

    //Heading for intersecting points top left corner
    setcolor(GREEN);
    char heading[100];
    sprintf(heading, "INTERSECTIONS");
    outtextxy(10, 10, heading);
      
    //Find the intesecting Points
        double a = -5;
        double b = 5;
        double eps = 0.001;
        double step = 0.1;
        double x1 = a, x2 = a + step;
        bool foundRoot = false;
    
        while (x2 <= b) {
            if (overal(x1) * overal(x2) < 0) {
                bisection(x1, x2, eps);
                foundRoot = true;
            }
            x1 += step;
            x2 += step;
        }
    //---------
   
    // Shading the Enclosed area region
    setfillstyle(4, BLACK);
    for (x = *min_element(answers.begin(), answers.end()); x <= *max_element(answers.begin(), answers.end()); x += 0.01) {
        int px1 = getmaxx() / 2 + x * scale;
        int py1 = getmaxy() / 2 - func(x) * scale;
        int py2 = getmaxy() / 2 - func2(x) * scale;
        int px2 = getmaxx() / 2 + x * scale + 3;
        bar(px1, py1, px2, py2);
    }
    //---------------
    
    
    // calculate the areas of the shaded regions using the trapezoidal rule
    double area1 = trapz(answers[0], answers[1], 100);
    double area2 = trapz(answers[1], answers[2], 100);


    // display the areas on the graph
    
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    char label1[20];
    sprintf(label1, "Area 1 = %.3f", area1);
    outtextxy(getmaxx() / 2 - 150 , getmaxy() / 2 - 290, label1);
    char label2[20];
    sprintf(label2, "Area 2 = %.3f", area2);
    outtextxy(getmaxx() / 2 + 70, getmaxy() / 2  + 180, label2);
    
    setcolor(BLACK);
    char text[100];
    sprintf(text, "Total Area = %0.3f", area1+area2);
    settextstyle(9, HORIZ_DIR, 2);
    outtextxy(getmaxx() - 270, getmaxy()/2- 150, text);
    
    //------------------
    


    getch();
    closegraph();
    return 0;
}



int x = 10, y = 35; // starting coordinates for first text

void bisection(double a, double b, double eps) {
    double c = (a + b) / 2;
    while (abs(b - a) > eps) {
        if (overal(c) == 0) {
            std::cout << "Root: " << c << std::endl;
            return;
        }
        else if (overal(a) * overal(c) < 0)
            b = c;
        else
            a = c;
        c = (a + b) / 2;
	}
	double int_y = func(c) + func2(c);
	std::cout<<int_y;
	
        setcolor(BLACK);
	    char text[100];
        sprintf(text, "Point  [ %0.3f, %0.3f ]", c, int_y);
        outtextxy(x, y, text);   // write the text to the screen
        y += 20; // move down by 25 pixels (next text)
        answers.push_back(c);
}
// Using the Bisection method

double func(double x) {
    return pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5;
}

double func2(double x) {
   return -sin(x) - cos(x);
}

double overal(double x) {
    return func(x) - func2(x);
}


