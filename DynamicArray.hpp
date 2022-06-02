

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
private:
    int count;           // кол-во членов массива
    T * pointer_data;    // указатель на начало массива

public:
    DynamicArray (): count(0) // инициализация пустая - конструктор по умолчанию
    {
        pointer_data = nullptr;
    }
    
    DynamicArray (int size) : count(size) // инициализация - конструктор создание массива размерностью size
    {
        pointer_data = new T[size];
    }
    
    DynamicArray (int size, T item) : count(size) // инициализация - конструктор создание массива размерностью size  и инициализировнного начальным значением
    {
        pointer_data = new T[size];
        for (int i=0; i<size; i++)
            pointer_data[i]=item;
    }
    
    DynamicArray (T * items, int size) : count(size) // конструктор  - создания массива из переданного массива
    {
        pointer_data = new T[size];
        for  (int i = 0; i < size; i++)
           pointer_data[i] = items[i];
    }
    
    DynamicArray (const DynamicArray<T> & array) : count(array.count) //конструктор копирующий (глубоко)
    {
        if (array.count != 0)
        {
            pointer_data = new T[array.count];
            for (int i = 0; i < array.count; i++)
                pointer_data[i] = array.pointer_data[i];
        }
        else
            pointer_data = nullptr;
    }
    
//    ~DynamicArray()  // деструктор
//    {
//        delete[] pointer_data;
//    }
    
    T Get (int index) //декомпозиция - получение значения элемента массива по индексу
    {
        if ((index < 0))
        {
            cout << "IndexOutOfRange" << endl;
            return this->pointer_data[0];
        }
        if (index >= this->count)
        {
            cout << "IndexOutOfRange" << endl;
            return this->pointer_data[this->count-1];
        }
        return  this->pointer_data[index];
    }
    
    
    int Get_size () // декомпозиция - получение размера массива
    {
        return this->count;
    }
    
    void Set (int  index, T value) // присваивание элементу массива значения
    {
        if ((index >= 0) && (index <= this->count))
        {
            this->pointer_data[index] = value;
            return;
        }
        cout << "IndexOutOfRange" << endl;
        return;
    }
    
    void Resize (int newSize)
    {
        if (newSize >= 0)
        {
            T * temp_pointer_data = new T[newSize];
            size_t temp_count = (newSize > this->count) ? this->count : newSize;
            for (int i=0; i < temp_count; i++)
                temp_pointer_data[i] = this->pointer_data[i];
            delete [] this->pointer_data;
            this->pointer_data = temp_pointer_data;
            this->count = newSize;
            return;
        }
        cout << "NewSizeOutOfRange" << endl;
    }
    
    void Print ()
    {
        for (int i=0; i < this->count; i++)
            cout << this->pointer_data[i] <<"  ";
        cout <<  endl;
    }
    
    T operator [] (int index)
    {
        return Get(index);
    }
    
};


#endif /* DynamicArray_hpp */
