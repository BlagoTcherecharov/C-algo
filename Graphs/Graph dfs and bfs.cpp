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
        if (gr[i]->key==c)
            flag = 1;
    return flag;
}

int search_arc(link* gr[5], char c1, char c2)
//c1 и c2 - ключовите стойности на възлите, които
//свързва търсената дъга
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

void add_node(link* gr[n], char c) // c е добавената стойност
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

void del_node(link* gr[n], char c)
{
    if (search_node(gr, c))
    {
        int i = 0;
        while (gr[i]->key != c) ;
            i++;
        link* p;
        link *q=gr[i];
        while (gr[i] != NULL)
        {
            p = gr[i];
            gr[i] = p->next;
            delete p;
        }
        
        for (i=0;i<n;i++)
        {
            if (gr[i])
            {
                p = gr[i];
                while ((p->key != c) && (p->next != NULL))
                {
                    q = p;
                    p = p->next;
                }
            }
            if (p->key == c)
            {
                q->next = p->next;
                delete p;
            }
        }
    }
    else { cout << "Graph doesn't have that node!"; }
}

void del_arc(link* gr[n], char c1, char c2)
{
    if (search_arc(gr, c1, c2))
    {
        int i = 0;
        while (gr[i]->key != c1)
            i++;
        link* p = gr[i], * q=gr[i];
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


/*
void bfs(link* gr[n], char k)
{
    int m[n]; // масив за регистриране на обходените върхове
    memset(m, 0, 10);
    init_que(); //инициализация на помощната опашка
    push_queue(k); //поместване в опашка на първия елемент
    while (!empty_queue()) //докато опашката не е празна
    {
 // cout << "------------------";
        char s = pop_queue(); //извличане на поредния елемент от опашката
        int j = convert(gr,s); //функция, която връща индекса на елемента на масива от списъците на съседство, чиято стойност е k.
        if (m[j] == 0) //Възелът не е посетен
        {
            m[j] = 1;
            cout << s << " ";//регистриране и визуализация на възела
 //cout << "---------";
        }
        for (link* t = gr[j]; t != NULL; t = t->next)
        {
            int h = convert(gr, t->key);
            if (m[h] == 0) // възела не е посетен
            push_queue(t->key); // включване на възела в опашката
        }
    }
}
*/

int convert(link* gr[n], char k)
{
    for(int i = 0; i < n; i++)
    {
        if(gr[i]->key == k)
            return i;
    }
    
    return -1;
}

// функция реализираща обхождане в дълбочина
void dfs(link* gr[n], char k, int m[])
{
    cout << k << " ";
    int j = convert(gr, k);
    m[j] = 1;
    for (link* t = gr[j]->next; t != NULL; t = t->next)
    {
        int h = convert(gr, t->key);
        if (m[h]==0)
            dfs(gr, t->key, m);
    }
}

int main()
{
    link* gr[n];
    int m[n];
    memset(m, 0, n);
    
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
    
    dfs(gr, a, m);
}
