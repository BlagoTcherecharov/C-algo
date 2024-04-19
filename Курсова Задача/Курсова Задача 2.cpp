#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapsort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void showPyramid(int array[], int depth, int N) 
{
    int index = 0;
    for (int i = 0; i < depth + 1; i++) 
    {
        for (int j = 0; j < pow(2, i); j++) 
        {
            if(index >= N)
                break;
            cout << array[index++] << " ";
            
        }
        cout << endl;
    }
}

int findDepth(int N) 
{
    if(N == 1)
        return 0;
    return sqrt(N);
}

void findLeaves(int array[], int depth, int N)
{
    for(int i = pow(2, depth) - 1; i < N; i++)
        cout << array[i] << " ";
}

int main() 
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    
    int array[N];
    srand (time(NULL));
    for (int i = 0; i < N; i++) 
    {
        array[i] = rand() % 100; 
    }

    heapsort(array, N);

    int depth = findDepth(N);
    cout << "Depth of pyramid: " << depth << endl;
    
    cout << "Pyramid:" << endl;
    showPyramid(array, depth, N);
    
    cout << "Leaves:" << endl;
    findLeaves(array, depth, N);
    
    return 0;
}
