#include <iostream>
using namespace std;

#ifdef DOUBLE
#define MYTYPE double
#elif FLOAT
#define MYTYPE float
#else
#define MYTYPE int
#endif

template<class cTYPE>
class myerr {
  private:
    cTYPE x, y;

  public:
    myerr(cTYPE a, cTYPE b) {
      x = a;
      y = b;
    }

    void print() {
      cout << "x,y pair = " << x << " " << y << endl;
    }
};

template<class dTYPE>
double mydiv(dTYPE x, dTYPE y) throw(myerr<dTYPE>) {
  dTYPE ZERO = (dTYPE) 0;
  if (y == ZERO) {
    myerr<dTYPE> e(x,y);
    throw e;
  }
  return (double)x/(double)y;
}

int main() {
  MYTYPE x = 0;
  MYTYPE y = 0;

  cout << "Enter x,y pair = " << endl;
  cin >> x >> y;

  double z = 0.0;
  try {
     z = mydiv(x,y);
  } catch (myerr<MYTYPE> &e) {
    e.print();
    return -1;
  }

  cout << "Result is = " << z << endl;

  return 0;
}
