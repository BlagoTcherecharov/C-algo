#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next;
} *start = NULL;

void push(int n)
{
	elem* p = start;
	start = new elem;
	start->key = n;
	start->next = p;
}

bool pop()
{
	if (start)
	{
		int n = start->key;
		elem* p = start;
		start = start->next;
		delete p;
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string equation;

	cin >> equation;

	bool equal = true;

	for (size_t i = 0; i < equation.length(); i++)
	{
		if (equation[i] == '(')
		{
			push(1);
		}
		else if (equation[i] == ')')
		{
			equal = pop();
		}
		if (equal != true)
			break;
	}
	if (equal == true && start == NULL)
		cout << "Equal number of brackets";
	else
		cout << "Not equal number of brackets";
}
