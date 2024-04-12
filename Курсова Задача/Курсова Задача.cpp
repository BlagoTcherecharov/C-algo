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


int findDepth(int N, int ans) 
{
    if(N == 0)
    {
        return ans - 1;
    }
    else if(N < ans)
    {
        return ans;
    }
    else
    {
        N-=ans;
        ans++;
        return findDepth(N, ans);
    }
}

int lastRow(int N, int depth)
{
    int rest = 0;
    int counter = 1;
    while(counter < depth)
    {
        rest += counter;
        counter ++;
    }
    return rest;
}

void showPyramid(int array[], int depth, int N) 
{
    int index = 0;
    for (int i = 1; i <= depth; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            cout << array[index++] << " ";
            if(index >= N)
                break;
        }
        cout << endl;
    }
}

/*
void showPyramid(int array[], int depth, int N) 
{
    int index = 0;
    int maxWidth = pow(2, depth - 1);
    
    for (int i = 1; i <= depth; i++) 
    {
        int numElements = pow(2, i - 1);
        
        int spaces = (maxWidth - numElements) / 2;
        
        for (int s = 0; s < spaces; s++)
            cout << " "; 
        
        for (int j = 0; j < numElements; j++) 
        {
            if(index < N)
            {
                cout << array[index++] << " ";
            }
        }
        
        cout << endl;
    }
}
*/
void findLeaves(int array[], int N, int depth) 
{
    int rest = lastRow(N, depth);
    for(int i = rest; i < N; i++)
    {
        cout << array[i] << " ";
    }
}

int main() 
{
    int N, ans = 1;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    
    int array[N];
    srand (time(NULL));
    for (int i = 0; i < N; i++) 
    {
        array[i] = rand() % 100; 
    }

    heapsort(array, N); 

    int depth = findDepth(N, ans);
    cout << "Depth of pyramid: " << depth << endl;
    
    cout << "Pyramid:" << endl;
    showPyramid(array, depth, N);

    int rest = 0;
    cout << "Leaves:" << endl;
    findLeaves(array, N, depth);
    
    return 0;
}
