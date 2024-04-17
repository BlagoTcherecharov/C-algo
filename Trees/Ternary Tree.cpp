#include <iostream>

using namespace std;

struct elem
{
    int key;
    elem *left, *middle, *right;
};

int height = 0;

void add(int n, elem* &t)
{
    if (t == NULL)
    {
         t = new elem; 
         t->key = n;
         t->left = t->middle, t->right = NULL;
    }
    else
    {
        if (t->left == NULL && t->middle == NULL && t->right == NULL)
        {
            add(n, t->left);
            height++;
        }
        else
            if (t->left != NULL && t->middle != NULL && t->right != NULL)
                add(n, t->left);
        else
            if (t->left == NULL)
                add(n, t->left);
        else
            if (t->middle == NULL)
                add(n, t->middle);
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
        pre(t->middle);
        pre(t->right);
    }
}

void post(elem* t)
{
    if (t)
    {
        post(t->left);
        post(t->middle);
        post(t->right);
        cout << t->key << " ";
    }
}

void leaves(elem* t)
{
    if (t)
    {
        leaves(t->left);
        leaves(t->middle);
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
        
    cout << height << endl;
    pre(start);
    cout << endl;
    post(start);
    cout << endl;
    leaves(start);
}
