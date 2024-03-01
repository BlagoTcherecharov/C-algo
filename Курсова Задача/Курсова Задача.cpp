#include <iostream>
#include <ctime>

using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int array[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) 
    {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void heapsort(int array[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);

        heapify(array, i, 0);
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
        findDepth(N, ans);
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
