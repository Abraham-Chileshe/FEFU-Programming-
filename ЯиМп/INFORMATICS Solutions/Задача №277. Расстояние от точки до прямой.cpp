#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
  double x, y;
  double a, b, c;

  cin >> x >> y >> a >> b >> c;

  double distance = abs (a * x + b * y + c) / sqrt (a * a + b * b);	//formula

  std::cout << std::fixed;
  std::cout << std::setprecision (5);
  std::cout << distance;
  return 0;
}
