#include <iostream>
#include <cstring>

using namespace std;

const int n = 4;


struct link
{
    char key;
    link* next;
};

void init(link* gr[n])
{
    for (int i = 0; i < n; i++)
        gr[i] = NULL;
}

int search_node(link* gr[n], char c)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (gr[i])
            if (gr[i]->key == c)
                flag = 1;
    return flag;
}

int search_arc(link* gr[5], char c1, char c2)
{
    int flag = 0;
    if (search_node(gr, c1) && search_node(gr, c2))
    {
        int i = 0;
        while (gr[i]->key != c1)
            i++;
        link* p = gr[i];
        while (p->key != c2 && p->next != NULL)
            p = p->next;
        if (p->key == c2)
            flag = 1;
    }
    return flag;
}

void add_node(link* gr[n], char c)
{
    if (search_node(gr, c))
    {
        cout << "\nNode exists!\n";
    }
    else
    {
        int j = 0;
        while (gr[j] && (j < n))
            j++;
        if (gr[j] == NULL)
        {
            gr[j] = new link;
            gr[j]->key = c;
            gr[j]->next = NULL;
        }
        else
        {
            cout << "\nStruct is full!\n";
        }
    }
}

void add_arc(link* gr[n], char c1, char c2)
{
    int i = 0; link* p;
    if (search_arc(gr, c1, c2))
    {
        cout << "\nArc already exits!";
    }
    else
    {
        if (!(search_node(gr, c1)))
            add_node(gr, c1);
        if (!(search_node(gr, c2)))
            add_node(gr, c2);
        while (gr[i]->key != c1)
            i++;
        p = new link;
        p->key = c2;
        p->next = gr[i]->next;
        gr[i]->next = p;
    }
}

void del_node(link* gr[], char c)
{
    if (search_node(gr, c))
    {
        int i = 0;
        while (gr[i] && gr[i]->key != c)
            i++;

        if (gr[i])
        {
            link* p = gr[i];
            gr[i] = p->next;
            delete p;
        }

        for (i = 0; i < n; i++)
        {
            if (gr[i])
            {
                link* p = gr[i];
                link* q = nullptr;
                while (p && p->key != c)
                {
                    q = p;
                    p = p->next;
                }
                if (p)
                {
                    if (q)
                        q->next = p->next;
                    else
                        gr[i] = p->next;
                    delete p;
                }
            }
        }
    }
    else
    {
        cout << "This node doesn't exist!";
    }
}


void del_arc(link* gr[n], char c1, char c2)
{
    if (search_arc(gr, c1, c2))
    {
        int i = 0;
        while (gr[i]->key != c1)
            i++;
        link* p = gr[i], * q = gr[i];
        while (p->key != c2)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    else { cout << "\nGraph doesn't have that arc!"; }
}

struct elem
{
    char key;
    elem* next;
}*first, * last;

void init_que()
{
    first = NULL;
    last = NULL;
}

void push_queue(char k)
{
    elem* p = last;
    last = new elem;
    last->key = k;
    last->next = NULL;
    if (p != NULL) p->next = last;
    if (first == NULL)
    {
        first = last;
    }
}

char pop_queue()
{
    char s = first->key;
    elem* p = first;
    first = first->next;
    delete p;
    return s;

}

bool empty_queue()
{
    if (first == NULL)
        return true;
    else
        return false;
}

int convert(link* gr[n], char k)
{
    for (int i = 0; i < n; i++)
    {
        if (gr[i]->key == k)
            return i;
    }

    return -1;
}

void bfs(link* gr[n], char k)
{
    int m[n]; 
    for (int i = 0; i < n; i++)
        m[i] = 0;
    init_que();
    push_queue(k); 
    while (!empty_queue()) 
    {
        char s = pop_queue();
        int j = convert(gr, s);
        if (m[j] == 0)
        {
            m[j] = 1;
            cout << s << " ";
        }
        for (link* t = gr[j]; t != NULL; t = t->next)
        {
            int h = convert(gr, t->key);
            if (m[h] == 0)
                push_queue(t->key);
        }
    }
}


void dfs(link* gr[n], char k, int m[])
{
    cout << k << " ";

    int j = convert(gr, k);
    m[j] = 1;
    for (link* t = gr[j]->next; t != NULL; t = t->next)
    {
        int h = convert(gr, t->key);
        if (m[h] == 0)
            dfs(gr, t->key, m);
    }
}

int main()
{
    link* gr[n];
    int m[n];

    init(gr);

    char a = 'A';
    char b = 'B';
    char c = 'C';
    char d = 'D';


    add_node(gr, a);
    add_node(gr, b);
    add_node(gr, c);
    add_node(gr, d);

    add_arc(gr, a, b);
    add_arc(gr, a, c);
    add_arc(gr, b, d);
    add_arc(gr, c, d);

    bfs(gr, a);

    cout << endl;

    for (int i = 0; i < n; i++)
        m[i] = 0;
    dfs(gr, a, m);
}
