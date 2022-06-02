

#ifndef LinkedListSequence_hpp
#define LinkedListSequence_hpp

template <class T>
class LinkedListSequence : public Sequence<T>
{
    private:
    LinkedList<T>* arr = new LinkedList<T>;

    public:

    LinkedListSequence (T* items, int count)
    {
        *arr = LinkedList<T>(items,count);
    }

    LinkedListSequence ()
    {
        *arr = LinkedList<T>();
    }

    T GetFirst() override
    {
        T k = arr -> GetFirst();
        return k;
    }

    T GetLast() override
    {
        T k = arr -> GetLast();
        return k;
    }

    T Get(int index) override
    {
        T k = arr -> Get(index);
        return k;
    }

    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        LinkedListSequence<T>* a = new LinkedListSequence<T>();

        a -> arr = arr -> GetSubList(startIndex,endIndex);
        return a;
    }

    int GetLength() override
    {
        int k = arr -> GetLength();
        return k;
    }

    void Append(T item) override
    {
        arr -> Append(item);
    }

    void Prepend(T item) override
    {
        arr -> Prepend(item);
    }

    void InsertAt(T item, int index) override
    {
        arr -> InsertAt(item,index);
    }

    LinkedListSequence<T>* Concat(LinkedListSequence<T>* list)
    {
        LinkedListSequence<T>* a = new LinkedListSequence<T>;
        a -> arr = arr -> Concat(list -> arr);
        return a;
    }

    void Print()
    {
        arr -> Print();
    }

} ;

#endif /* LinkedListSequence_hpp */
