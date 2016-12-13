#include <iostream>
using namespace std;

template<class dTYPE>
dTYPE div(dTYPE x, dTYPE y) {
  if (y == (dTYPE) 0.0) {
    throw "division by zero !!!";
  }
  return x/y;
}

int main() {
  double x = 0.0;
  double y = 0.0;

  cout << "Enter x,y pair = " << endl;
  cin >> x >> y;

  double z = 0.0;
  try {
    z = div(x,y);   
  } catch (const char * str) {
    cout << str << endl;
    return -1;
  }

  cout << "Result is = " << z << endl;

  return 0;
}
