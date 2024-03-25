#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int seq_search(int arr[], int lf, int rt, int key)
{
	for (size_t i = lf; i <= rt; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int jmp_search(int arr[], int n, int key, unsigned step)
{
	int i, rt, lf;
	for (i = 0; i < n && arr[i] < key; i += step);
	if (i < step)
		lf = 0;
	else
		lf = i + 1 - step;
	if (n < i)
		rt = n - 1;
	else
		rt = i;
	return seq_search(arr, lf, rt, key); 
}

int binary(int arr[], int l, int r, int k)
{
    while (l <= r) 
    {
        int m = l + (r - l) / 2;
 
        if (arr[m] == k)
            return m;
 
        if (arr[m] < k)
            l = m + 1;
 
        else
            r = m - 1;
    }
 
    return -1;
}

int binary_rec(int arr[], int l, int r, int k)
{
    if (r >= l) 
    {
        int m = l + (r - l) / 2;
 
        if (arr[m] == k)
            return m;
 
        if (arr[m] > k)
            return binary_rec(arr, l, m - 1, k);
 
        return binary_rec(arr, m + 1, r, k);
    }
 
    return -1;
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
	int arr[1000];
	int step, k, n = sizeof(arr) / sizeof(arr[0]);

    //srand(time(0));

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 5001;
	}
	cin >> k >> step;

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

	auto start = high_resolution_clock::now();
	int pos = jmp_search(arr, n, k, step);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);

    auto start1 = high_resolution_clock::now();
    int pos1 = binary(arr, 0, n - 1, k);
    auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    int pos2 = binary_rec(arr, 0, n - 1, k);
    auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

	cout << "\nVremeto za izpalnenie na jmp_search e: " << duration.count() << " nanoseconds" << endl;
	cout << pos << endl;
	cout << "\nVremeto za izpalnenie na binary_search e: " << duration1.count() << " nanoseconds" << endl;
	cout << pos1 << endl;
	cout << "\nVremeto za izpalnenie na binary_recursion e: " << duration2.count() << " nanoseconds" << endl;
	cout << pos2 << endl;
	
	print(arr, n);
}
