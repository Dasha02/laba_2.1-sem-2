

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <assert.h>

using namespace std;


template <class T>
class Nudl
{
    public:
   
    T data;        // то что там хранится
    Nudl* next;     /// указатель на след. об.
    
};


template <class T>
class LinkedList
{
    private:
    
    Nudl<T> * first = new Nudl<T>; // ук. начала списка
    int size; // размер
    
    public:
    
    LinkedList() : size(0)
    {
//        first -> data = 1357;
        first -> next = NULL;
        
    }
    
    LinkedList(T arr, int n) : size(n)
    {
        Nudl<T>* p = new Nudl<T>;
        
        p -> data = arr;
        p -> next = NULL;
        first = p;
        
        for(int i = 1; i < n; i++)
        {
            
            Nudl<T>* p2 = new Nudl<T>;
            p2 -> data = arr;
            p2 -> next = NULL;
        
            while(p -> next != NULL)
            {
                p = p -> next;
            }
            p -> next = p2;
        }
    }
    
    LinkedList(T* arr, int n) : size(n)
    {
        Nudl<T>* p = new Nudl<T>;
        
        p -> data = *arr;
        p -> next = NULL;
        first = p;
        
        for(int i = 1; i < n; i++)
        {
            
            Nudl<T>* p2 = new Nudl<T>;
            p2 -> data = *(arr + i);
            p2 -> next = NULL;
        
            while(p -> next != NULL)
            {
                p = p -> next;
            }
            p -> next = p2;
        }
    
    }
    
    LinkedList(LinkedList<T> & a) : size(a.size)   // копирующий конструктор
    {
        Nudl<T>* p = new Nudl<T>;
        first = p;
        Nudl<T>* pa = a.first;
        p -> data = pa -> data;
        p -> next = NULL;
        while (pa -> next != NULL)
        {
            pa =  pa -> next;
            Nudl<T>* p_this = new Nudl<T>;
            p_this -> data = pa -> data;
            p_this -> next = NULL;
            p -> next = p_this;
            p = p -> next;
        }
        
    }
    
    LinkedList(LinkedList<T> a, LinkedList<T> b) : size(a.size + b.size) // об. 2 списков
    {
        Nudl<T>* p= new Nudl<T>;
        
        p = a.first;
        first = p;
        
        while(p -> next != NULL)
        {
          p = p -> next;
        }
        
        p -> next = b.first;
        
    }
    
    int GetLength()
    {
        int result = 0;
        Nudl<T> * p =first;
        while(p != NULL)
        {
           result++;
           p = p -> next;
        }
        
        return result;
    }
    
    int GetLength2()
    {
        return size;
    }
    
    T GetFirst() // возвращ. значение первого элемента
    {
        Nudl<T>* p = first;
        int n= 0;
        
        while(p != NULL)
        {
            p = p -> next;
            n ++;
        }
        
        if (n == 0)
            assert(0);
        
        T result;
        
        result = (first -> data);
        
        return result;
    }
    
    T GetLast()
    {
        Nudl<T>* p = new Nudl<T>;
        p = first;
        int n= 0;               // можно сократить и использовать size
        while(p != NULL)        //
        {                       //
            p = p -> next;      //
            n ++;               //
        }                       //
        
        if (n == 0)
            assert(0);
        
        T result;
        p = first;
        while(p -> next != NULL)
        {
            p = p -> next;
        }
        
        result = p -> data;
        
        return result;
    }
    
    T Get(int n)
    {
        Nudl<T>* p = first;
        int h= 0;               // можно сократить и использовать size
        while(p != NULL)        //
        {                       //
            p = p -> next;      //
            h ++;               //
        }                       //
        if(n >= h || n < 0)
            assert(0);
        
        T result;
        p = first;
        for(int i = 0; i < n; i++)
        {
            p = p -> next;
        }
        
        result = p -> data;
        
        return result;
    }
    
    LinkedList<T>* GetSubList(int str, int end)  // взять часть списка
    {
        Nudl<T>* p = first;
        int n= 0;
        while(p != NULL)
        {
            p = p -> next;
            n ++;
        }
        if(n == 0 || str < 0 || end < 0 || end < str)
            assert(0);
        LinkedList<T>* result = new LinkedList<T>();
        p = first;
        for(int i = 0; i < str; i++)
            p = p -> next;
        (result -> first) = p;
        for (int i = 0; i < (end - str); i++)
            p = p -> next;
        p -> next = NULL;
        return result;
    }
    
    void Append(T item)  // добавление последнего эл.
    {
        size++;
        Nudl<T>* p = first;
        Nudl<T>* pnew = new Nudl<T>;
        pnew -> data = item;
        pnew -> next = NULL;
        while(p -> next != NULL)
            p = p -> next;
        p -> next = pnew;
        return;
    }
    
    void Prepend(T item) // добавление первого элем.
    {
        size++;
        Nudl<T>* p = new Nudl<T>;
        p -> data = item;
        p -> next = first;
        first = p;
        return;
    }

    void InsertAt(T item, int n) // вставка нового по индексу
    {
        Nudl<T>* p = first;
        int h= 0;
        while(p != NULL)
        {
            p = p -> next;
            h ++;
        }
        if(n >= h || n <= 0)
            assert(0);
        Nudl<T>* pnew = new Nudl<T>;
        p = first;
        for (int i = 1; i < n; i++)
            p = p -> next;
        Nudl<T>* temp = p -> next;
        pnew -> data = item;
        pnew -> next = temp;
        p -> next = pnew;
        size++;
    }
    
    LinkedList<T>* Concat(LinkedList<T> *b)
    {
        LinkedList<T>* result = new LinkedList<T>();
        
        (result -> first) = first;
        Nudl<T>* p = first;
        while(p -> next != NULL)
            p = p -> next;
        p -> next = (b -> first);
        result -> size = size + b -> size;
        return result;
        
    }
    
    void Print()
    {
        Nudl<T>* p = first;
        while(p != NULL)
        {
            cout<< p -> data<<"  ";
            p = p -> next;
        }
        cout<<endl;
    }
    
};

#endif /* LinkedList_hpp */
