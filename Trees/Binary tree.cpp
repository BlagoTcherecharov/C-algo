#include <iostream>

using namespace std;

struct elem
{
    int key;
    elem *left, *right;
};

void add(int n, elem* &t)
{
    if (t == NULL)
    {
         t = new elem; 
         t->key = n;
         t->left = t->right = NULL;
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
            add(n, t->left);
        else
            if (t->left != NULL && t->right != NULL)
                add(n, t->left);
        else
            if (t->left == NULL)
                add(n, t->left);
        else
            add(n, t->right);
    }
}

void pre(elem* t)
{
    if (t)
    {
        cout << t->key << " ";
        pre(t->left);
        pre(t->right);
    }
}

void post(elem* t)
{
    if (t)
    {
        post(t->left);
        post(t->right);
        cout << t->key << " ";
    }
}

void inf(elem* t)
{
    if (t)
    {
        inf(t->left);
        cout << t->key << " ";
        inf(t->right);
    }
}

void leaves(elem* t)
{
    if (t)
    {
        leaves(t->left);
        leaves(t->right);
        if(!t->left || !t->right)
            cout << t->key << " ";
    }
}

int main() 
{
    const int SIZE = 7;
    elem *start = NULL;
    int array[SIZE] = {6,4,3,2,5,8,7};
    
    for(int i = 0; i < SIZE; i++)
        add(array[i], start);
    
    pre(start);
    cout << endl;
    post(start);
    cout << endl;
    inf(start);
    cout << endl;
    leaves(start);
}
