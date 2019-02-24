#include <fstream>
#include <iostream>

using namespace std;	

int main()
{
	ifstream input("541A-Divison2");a
	int w1, h1, w2, h2, answer = 0;
	
	while (input >> w1 >> h1 >> w2 >> h2) {
	}

	answer = (2 * (w1 + h1 + h2)) + 4;
	cout << answer;

	return 0;
}	
