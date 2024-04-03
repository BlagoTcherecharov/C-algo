#include <iostream>
#include <array>
#include <chrono>

using namespace std::chrono;
using namespace std;

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int array[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(int array[], int low, int high) 
{
    
    int pivot = array[high];
  
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (array[j] <= pivot) 
        {
                i++;
                swap(&array[i], &array[j]);
            }
        }
  
    swap(&array[i + 1], &array[high]);
  
    return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void merge(int arr[], int p, int q, int r) 
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        }   
        else 
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main() 
{
    const int SIZE = 1000;
    
    int array[SIZE];
    srand(time(0));
    
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 5000;
    }
    auto start = high_resolution_clock::now();
    quickSort(array, 0, SIZE - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    printArray(array, SIZE);
    
    cout << "Duration quicksort: " << duration.count() << "nanoseconds" << endl;
    
    auto start1 = high_resolution_clock::now();
    mergeSort(array, 0, SIZE - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    
    printArray(array, SIZE);
    
    cout << "Duration mergesort: " << duration1.count() << "nanoseconds" << endl;
}
