#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next;
} *start = NULL;

void insert(int n)
{
	elem* p = start, * q;
	if (start == NULL)
	{
		start = new elem;
		start->key = n;
		start->next = NULL;
	}
	else
	{
		q = new elem;
		q->key = n;
		q->next = NULL;
		while (p->next)
			p = p->next;
		p->next = q;
	}
}

void Getprime(int start, int end)
{
	for (int num = start; num <= end; num++)
	{
		bool prime = true;
		double numSqrt = sqrt(num);
		for (int div = 2; div <= numSqrt; div++)
		{
			if (num % div == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			insert(num);
		}
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
}

int main()
{
	Getprime(200, 300);
	print();
}
