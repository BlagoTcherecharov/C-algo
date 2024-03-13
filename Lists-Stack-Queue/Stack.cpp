#include <iostream>

using namespace std;

struct elem
{
	string key;
	elem* next;
}*start;

void push(string n)
{
	elem* p = start;
	start = new elem;
	start->key = n;
	start->next = p;
}

string pop(string& n)
{
	if (start)
	{
		n = start->key;
		elem* p = start;
		start = start->next;
		delete p;
		return n;
	}
	else
		return n = "empty";
}

int main()
{
	push("1. Ivan");
	push("2. Nikolay");
	push("3. Maria");
	push("4. George");
	string n;
	do {
		cout << n << endl;
		n = pop(n);
	} while (n != "empty");
}
