#include <iostream>

using namespace std;

struct elem
{
	string key;
	elem* next;
} *first = NULL, * last = NULL;

void Add_que(string n) 
{
	elem* p = last;
	last = new elem;
	last->key = n;
	last->next = NULL;
	if (p != NULL) p->next = last;
	if (first == NULL)
	{
		first = last;
	}
}

string remove(string& n)
{
	if (first)
	{
		n = first->key;
		elem* p = first;
		first = first->next;
		delete p;
		return n;
	}
	else
		return n = "error";
}

int main()
{

	Add_que("Message One");
	Add_que("Message Two");
	Add_que("Message Three");
	Add_que("Message Four");
	string msg;
	while (msg != "error")
	{
		cout << msg << endl;
		 msg = remove(msg);
	}
}
