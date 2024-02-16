#include <iostream>

using namespace std;

int main() 
{
    const int SIZE = 3;
    
    int array[SIZE][SIZE];
    
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            cin >> array[i][j];
            
    for(int i = 0; i < SIZE; i++)
    {
        int sum = 0;
        for(int j = 0; j < SIZE; j++)
            sum += array[i][j];
        cout << "Sum row " << i + 1 << " is " << sum << endl;
    }
}
