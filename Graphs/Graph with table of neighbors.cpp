#include <iostream>

using namespace std;

const int EDGES = 4;

int matrix[EDGES][EDGES];

struct elem
{
	int key;
  elem* next;
}*start;

void AddEdge(int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void RemoveEdge(int i, int j)
{
    matrix[i][j] = 0;
    matrix[j][i] = 0;
}

bool HasEdge(int i, int j)
{
    if (matrix[i][j] == 1)
        return true;
    else return false;
}

void AddList(int j)
{
    elem* p = start, * q;
	if (start == NULL)
	{
		start = new elem;
		start->key = j;
		start->next = NULL;
	}
	else
	{
		q = new elem;
		q->key = j;
		q->next = NULL;
		while (p->next)
			p = p->next;
		p->next = q;
	}
}

void GetSuccessors(int i, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (matrix[i][j] == 1)
            AddList(j);
    }
}

void print()
{
	while (start != NULL)
	{
		elem* p = start;
		cout << start->key << " ";
		start = p -> next;
		delete p;
	}
	cout << endl;
}

int main() 
{
    AddEdge(0, 1);
    AddEdge(0, 2);
    AddEdge(1, 3);
    AddEdge(2, 3);
    
    GetSuccessors(0, EDGES);
    print();
    GetSuccessors(1, EDGES);
    print();
    GetSuccessors(2, EDGES);
    print();
    GetSuccessors(3, EDGES);
    print();
}
