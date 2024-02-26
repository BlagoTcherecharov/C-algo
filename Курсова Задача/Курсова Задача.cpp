#include <iostream>
#include <ctime>

using namespace std;

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

void buildPyramid(int array[], int depth, int N) 
{
    int index = 0;
    for (int i = 1; i <= depth; i++) {
        for (int j = 0; j < i; j++) {
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

int main() {
    int N, ans = 1;
    cout << "Enter the number of elements in the array: ";
    cin >> N;
    
    int array[N];
    srand (time(NULL));
    for (int i = 0; i < N; i++) 
    {
        array[i] = rand() % 100; 
    }

    int depth = findDepth(N, ans);
    cout << "Depth of pyramid: " << depth << endl;
    
    cout << "Pyramid:" << endl;
    buildPyramid(array, depth, N);

    int rest = 0;
    cout << "Leaves:" << endl;
    findLeaves(array, N, depth);
    
    return 0;
}
