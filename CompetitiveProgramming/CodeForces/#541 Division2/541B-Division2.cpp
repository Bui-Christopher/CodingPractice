#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;	

int main()
{
	int x, y, a=0, b=0, n, r = 1;
	ifstream input("541B-Division2.txt");

	input >> n;
	cout << "Cases: " << n;

	while (n > 0, n--) {
		input >> x >> y;
		r += max(0, min(x, y) - max(a, b) + (a != b));
		a = x;
		b = y;
	}

	cout << "\nThe output is " << r;

	return 0;
}	
