#include <iostream>

using namespace std;

int main()
{
	const int SIZE = 10;

	int array[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		cin >> array[i];
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << *(array + i) << " ";
	}
}
