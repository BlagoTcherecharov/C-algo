#include <iostream>

using namespace std;

int* Max(int array[], int SIZE)
{
	int temp = *array;
	int position = 0;

	for (size_t i = 1; i < SIZE; i++)
	{
		if (*(array + i) > temp)
		{
			temp = *(array + i);
			position = i;
		}
	}

	int result[2] = { temp, position };

	return result;
}

int* Min(int array[], int SIZE)
{
	int temp = *array;
	int position = 0;

	for (size_t i = 1; i < SIZE; i++)
	{
		if (*(array + i) < temp)
		{
			temp = *(array + i);
			position = i;
		}

	}
	int result[2] = { temp, position };

	return result;
}

void main()
{
	const int SIZE = 10;

	int array[SIZE] = { 7, 5, 2, 3, 4, 5, 6, 7, 8, 9 };

	int*min = Min(array, SIZE);
	int*max = Max(array, SIZE);

	cout << "Min is " << *min << " at position " << *(min + 1) + 1 << endl;
	cout << "Max is " << *max << " at position " << *(max + 1) + 1 << endl;
}
