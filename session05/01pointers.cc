#include <iostream>
using namespace std;

void f(int& x) {
  cout << &x << '\n';
  cout << sizeof(x) << '\n';
  //x = 0;
}

int main() {
	int a; // order of variables in memory is NOT GUARANTEED
  char c;
  // normally, we don't care where a lives, and we do not get to choose
  
  int b = 2;
  cout << &a << '\n'; // the address of a, where it lives in memory
  cout << &b << '\n'; // the address of b, where it lives in memory
  cout << &c << '\n'; // the address of c, where it lives in memory

	const int d = 54;
  f(b);
	//Error: f(d);
  // a pointer is declared in reverse
  // "what p points to is an int, therefore p is a pointer to int"
  int *p;
	//  cout << *p << '\n'; // probably crash, looking at random memory location
	//  *p = 124;
  int* q = &a; // spaces make no difference.  q is pointing to a
	*q = 5; // set the value of a   *q is an ALIAS to a
  *q = a; // same as saying a = a; DOES NOTHING
	q = &b; // point somwhere else
	cout << *q;
  //int *a,b; // don't do this: a is a pointer to int, b is int
  double x[10];
  cout << x << "\n"; // the name of an array is a pointer to the start
  double* dp = &x[0]; // point to the location of the first element
  double* dp2 = x; // point to the location of the first element
  dp++; // advance to the next element (8 bytes at a time)
  cout << *dp << '\n'; // what prints out????

  dp = x + 5; // &x[5] pointer addition works in terms of types, not bytes
  *dp = 2.5; // x[5] = 2.5
  p = (int*)x; //????? Types don't match.  But you can do this
  // if you try hard enough, and it is BAD
  cout << *p;
}
