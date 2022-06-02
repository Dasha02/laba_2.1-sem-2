//

#ifndef ArraySequence_hpp
#define ArraySequence_hpp
template <typename T>

class ArraySequence : public Sequence<T>
{
    private:
    DynamicArray<T>* array = new DynamicArray<T>;

    public:
    
    ArraySequence()
    {
        *array = DynamicArray<T>();
    }
    
    ArraySequence(int size)
    {
        *array =  DynamicArray<T>(size);
    }
    
    ArraySequence(int size, T item)
    {
        *array = new DynamicArray<T>(size, item);
    }
    
    ArraySequence(T* items, int size)
    {
        *array =  DynamicArray<T>(items,size);
    }

    ArraySequence(const ArraySequence<T> & arr)
    {
        *array =  DynamicArray<T>(arr);
    }
    
 //   ArraySequence(ArraySequence<T> d,ArraySequence<T> b)
 //   {
 //       *array = DynamicArray<T>(*d.arr,*b.arr);
 //   }

    T GetFirst() override
    {
        T result = array -> Get(0);

        return result;
    }

    T GetLast() override
    {
        int count = array -> Get_size();

        T result = array -> Get(count - 1);

        return result;
    }

    T Get(int index) override
    {
        T result = array -> Get(index);

        return result;
    }

    int GetLength() override
    {
        int result = array -> Get_size();
        return result;
    }

    void InsertAt(T item, int index) override
    {
        array -> Set(index, item);
    }

    void Append(T item) override
    {
        int size = array -> Get_size();

        array -> Resize(size + 1);
        array -> Set(size, item);

    }

    void Prepend(T item) override
    {
        int size = array -> Get_size();
        array -> Resize(size + 1);
        for (int i=size; i>0; i--)
            array -> Set(i,array -> Get(i-1));
        array -> Set(0, item);
    }

     ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        ArraySequence<T>* result = new ArraySequence<T>();
        
        return result;
    }

    ArraySequence<T>* Concat(ArraySequence<T>* list)
    {
        ArraySequence<T>* result = new ArraySequence<T>(*this,*list);
        
        return result;

    }

    void Print()
    {
        array -> Print();
    }
};
#endif /* ArraySequence_h */
