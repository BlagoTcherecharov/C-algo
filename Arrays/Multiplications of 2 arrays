#include <iostream>

using namespace std;

int main() 
{
    const int ROW = 2;
    const int COL = 3;
    
    int array1[ROW][COL];
    int array2[COL][ROW];
    int result[ROW][ROW];
    
    for(int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) 
            cin >> array1[i][j];
    }
    
    for(int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++) 
            cin >> array2[i][j];
    }
    
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < ROW; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < COL; k++) 
                result[i][j] += array1[i][k] * array2[k][j];
        }
    }
    
    for(int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < ROW; j++) 
            cout << result[i][j] << "\t";
        cout << endl;
    }
    
}
