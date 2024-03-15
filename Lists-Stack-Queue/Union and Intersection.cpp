#include <iostream>

using namespace std;

struct elem 
{
    int key;
    elem* next;
};

void insert(elem*& list, int n) 
{
    elem* p = list;
    if (list == NULL) 
    {
        list = new elem;
        list->key = n;
        list->next = NULL;
    } 
    else 
    {
        while (p->next)
            p = p->next;
        p->next = new elem;
        p->next->key = n;
        p->next->next = NULL;
    }
}

void print(elem* start) 
{
    while (start != NULL) 
    {
        cout << start->key << " ";
        start = start->next;
    }
    cout << endl;
}

void intersection(elem* list1, elem* list2) 
{
    elem* result = NULL;
    elem** lastPtrRef = &result;
    
    while (list1 != NULL && list2 != NULL) 
    {
        if (list1->key == list2->key) 
        {
            insert(*lastPtrRef, list1->key);
            lastPtrRef = &((*lastPtrRef)->next);
            list1 = list1->next;
            list2 = list2->next;
        } 
        else if (list1->key < list2->key) 
        {
            list1 = list1->next;
        } 
        else 
        {
            list2 = list2->next;
        }
    }
    
    cout << "Intersection: ";
    print(result);
    
    while (result != NULL) 
    {
        elem* p = result;
        result = result->next;
        delete p;
    }
}

void unionLists(elem* list1, elem* list2) 
{
    elem* result = NULL;
    elem** lastPtrRef = &result;

    while (list1 != NULL) 
    {
        insert(*lastPtrRef, list1->key);
        lastPtrRef = &((*lastPtrRef)->next);
        list1 = list1->next;
    }

    while (list2 != NULL) 
    {
        elem* p = result; 
        bool exists = false;
        while (p != NULL) 
        {
            if (p->key == list2->key) 
            {
                exists = true;
                break;
            }
            p = p->next;
        }
        if (!exists) 
        {
            insert(*lastPtrRef, list2->key);
            lastPtrRef = &((*lastPtrRef)->next);
        }
        list2 = list2->next;
    }

    cout << "Union: ";
    print(result);

    while (result != NULL) 
    {
        elem* p = result;
        result = result->next;
        delete p;
    }
}


int main() 
{
    elem* list1 = NULL;
    elem* list2 = NULL;
    
    insert(list1, 10);
    insert(list1, 20);
    insert(list1, 30);
    
    insert(list2, 20);
    insert(list2, 25);
    insert(list2, 30);
    
    intersection(list1, list2);
    unionLists(list1, list2);
}
