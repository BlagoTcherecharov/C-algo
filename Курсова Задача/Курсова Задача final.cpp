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
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

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
}

//Print pyramid
void showPyramid(int array[], int depth, int N) 
{
    int index = 0;
    //Cycle for number of rows
    for (int i = 0; i < depth + 1; i++) 
    {
        //Cycle for number of columns for each row
        for (int j = 0; j < pow(2, i); j++) 
        {
            if(index >= N)
                break;
            cout << array[index++] << " ";
            
        }
        cout << endl;
    }
}

//Depth of pyramid using the number of elements in the array
int findDepth(int N) 
{
    if (N == 1)
        return 0;
        
    int sum = 0, depth = 0;
    while (sum + pow(2, depth) <= N) {
        sum += pow(2, depth);
        depth++;
    }
    
    return depth;
}

//Function to find the leaves(elements that dont have a child)
void findLeaves(int array[], int depth, int N)
{
    int sum = 0, counter = 0;
    while (sum + pow(2, counter) <= N) {
        sum += pow(2, counter);
        counter++;
    }

    //Finding last row because elements are leaves
    int last_row = N - sum;

    //Finding leaves by knowing number of elements in the last row
    int i = pow(2, depth - 1) - 1 + ceil((double)last_row / 2);

    //Start printing from 1st leaf
    for(; i < N; i++)
        cout << array[i] << " ";
}

int main() 
{
    int N;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    
    int array[N];
    srand (time(NULL));

    //Adding random numbers from 1-100 in the array
    for (int i = 0; i < N; i++) 
    {
        array[i] = rand() % 100 + 1; 
    }

    //Calling function to sort the array as a pyramid
    heapsort(array, N);

    int depth = findDepth(N);
    cout << "Depth of pyramid: " << depth << endl;
    
    cout << "Pyramid:" << endl;
    showPyramid(array, depth, N);
    
    cout << "Leaves:" << endl;
    findLeaves(array, depth, N);
    
    return 0;
}
