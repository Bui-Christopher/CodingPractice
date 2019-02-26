#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;	

int main()
{
	//Method 1 -> Using Sort from STL
	int n, size, e;
	vector<int> vect;

	ifstream input("541C-Division2.txt");
	input >> n;
	size = n;

	while (n > 0, n--) {
		input >> e;
		vect.push_back(e);
	}

	sort(vect.begin(), vect.end());

	for (int x : vect)
		cout << x;

	cout << "\n";

	for (int i = 0; i < vect.size(); i++) {
		if (i%2 == 0)
			cout << vect.at(i);
	}
	for (int i = size - 1; i >= 0; i--)
		if (i %2 != 0)
			cout << vect.at(i);

	return 0;
}	
