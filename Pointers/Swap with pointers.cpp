#include <iostream>

using namespace std;

void main()
{
	int x = 5;
	int y = 2;
	int* px, * py;
	int temp;

	px = &x;
	py = &y;

	temp = *py;

	y = *px;
	x = temp;

	cout << x << "\t" << y;
}
