#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[], int n)
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i<n; i++)
	{
		for (int j = i + 1; j<n; j++) {
			if (arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
	cout << "Bubble sort: ";
	print(arr, n);
	cout << "Time: " << duration.count() << " nanoseconds" << endl;
}

void selection_sort(int arr[], int n)
{
    auto start = high_resolution_clock::now();
    int temp, min, index; 
  
    for (int i = 0; i < n - 1; i++) 
    { 
        min = arr[i]; 
        index = i;
        for (int j = i + 1; j < n; j++) 
        { 
            if (arr[j] < min) 
            {
                min = arr[j]; 
                index = j;
            }
        } 
        if (min != i) 
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index = temp];
        }
    } 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Selection sort: ";
    print(arr, n);
    cout << "Time: " << duration.count() << " nanoseconds" << endl;
}

void insertion_sort(int arr[], int n)
{
    auto start = high_resolution_clock::now();
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Insertion sort: ";
    print(arr, n);
    cout << "Time: " << duration.count() << " nanoseconds" << endl;
}

int main() 
{
    const int SIZE = 1000;
    int arr[SIZE];

    srand(time(0));

	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10001;
	}
	
	bubble_sort(arr, SIZE);
    selection_sort(arr, SIZE);
    insertion_sort(arr, SIZE);
}
