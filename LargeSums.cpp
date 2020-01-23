#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	unsigned long long int x = 0;
	unsigned long long int sum = 0;

	ifstream numbers;
	numbers.open("numbers.txt");

	numbers >> x;
	cout << x;

	return 0;
}