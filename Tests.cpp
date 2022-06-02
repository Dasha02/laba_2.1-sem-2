

#include "Tests.hpp"

int checkin(bool check, string message)
{
    if (check)
    {
        cout << "  " << message << "  ok" <<endl;
        return 0;
    }
    else
    {
        cout << "  " << message << "  errors" <<endl;
        return 1;
    }
}


int Test_DynamicArray()
{
    int errors=0;
    DynamicArray<int> test01;
    DynamicArray<int> test02 = DynamicArray<int>(4);
    DynamicArray<int> test03 = DynamicArray<int>(5, 1);
    int test04_1[] = {1, 4, 9, -3, 0, 5, 5};
    DynamicArray<int> test04= DynamicArray<int> (test03);
  //  test04.Print();
    test04.Set(3, 55);
    
   // test04.Print();
    
    errors = errors + checkin((test01.Get_size() == 0), "(DynamicArray ()) & (size_t Get_size ())");
    
    errors = errors + checkin((test02.Get_size() == 4), "(DynamicArray (size_t)) & (size_t Get_size ())");
    errors = errors + checkin(((test03.Get_size() == 5) && (test03.Get(1) == 1)),
                              "(DynamicArray (size_t size, T item)) & (size_t Get_size ()) & (T Get())");
    errors = errors + checkin(((test04.Get_size() == 5) && (test04.Get(0) == 1)),
                              "(DynamicArray (const DynamicArray<T>( & array)) & (size_t Get_size ()) & (T Get())");
    errors = errors + checkin((test04.Get(3) == 55),
                              "(void Set (int, T)) & (T Get())");
    test04.Resize(9);
    errors = errors + checkin((test04.Get_size() == 9),
                              "(void Resize (int newSize)) & (size_t Get_size())");
    
    
    errors = errors + checkin((test04[3] == 55),
                              "T operator [] (int index)");
    cout << "Тест DynamicArray проведен, количество выявленных ошибок = " << errors <<endl;
    return errors;
}
    

int Test_LinkedList()
{
    int errors=0;

    cout << "#####Тест инициализации:" << endl;
    LinkedList<int> test01;
    cout <<"test01 = LinkedList<T>() = ";
    test01.Print();
    errors = errors + checkin((test01.GetLength() == 1), "(LinkedList<T>()) & (GetLength())");
    cout << endl;
    
    LinkedList<int> test02 = LinkedList<int>(1, 10);
    cout <<"test02 = LinkedList<T>(1, 10) = ";
    test02.Print();
    errors = errors + checkin(((test02.GetLength() == 10) && (test02.Get(1) == 1)),
                              "(LinkedList<T>(1, 10)) & (GetLength() & (Get(1)))");
    cout << endl;
    
    int test03_1[] = {1, 4, 9, -3, 0, 5, 51};
    LinkedList<int> test03 = LinkedList<int>(test03_1, 7);
    cout <<"test03 = LinkedList<int>(test03_1, 7) = ";
    test03.Print();
    errors = errors + checkin(((test03.GetLength() == 7) && (test03.Get(6) == 51)),
                              "(LinkedList<T>(test03_1, 7)) & (GetLength() & (Get(6)))");
    cout << endl;
    
    LinkedList<int> test04 = LinkedList<int>(test03);
    cout <<"test04 = LinkedList<int>(test03) = ";
    test04.Print();
    errors = errors + checkin(((test04.GetLength() == 7) && (test03.Get(5) == 5)),
                              "(LinkedList<T>(test03)) & (GetLength() & (Get(5)))");
    cout << endl;
    

    cout << "#####Тест декомпозиции:" << endl;
    cout <<"test03.GetLength() = "<<test03.GetLength()<< endl;
    errors = errors + checkin((test03.GetLength() == 7)," GetLength() ");
    cout << endl;
  
        
    cout <<"test03.GetLength2() = "<<test03.GetLength2()<< endl;
    errors = errors + checkin((test03.GetLength2() == 7)," GetLength2() ");
    cout << endl;
        
    cout <<"test03.GetFirst() = "<<test03.GetFirst()<< endl;
    errors = errors + checkin((test03.GetFirst() == 1)," GetFirst() ");
    cout << endl;
    
    cout <<"test03.GetLast()  = "<<test03.GetLast()<< endl;
    errors = errors + checkin((test03.GetLast() == 51)," GetLast() ");
    cout << endl;
        
    cout <<"test03.Get(3) = " <<test03.Get(3)<< endl;
    errors = errors + checkin((test03.Get(3) == -3)," GetLast() ");
    cout << endl;
        
   
    LinkedList<int> * test05 = test04.GetSubList(1, 5);
    LinkedList<int> test06 = *test05;
    cout << "test06 = * test05 = * test04.GetSubList(1, 5) = ";
    test06.Print();
    //cout <<"test04 = ";
    //test04.Print();
    errors = errors + checkin((test06.GetLength() == 5)," GetSubList(1, 5) ");
    cout << endl;
    
        
    int test0331[] = {11, 41, 91, -31, 10, 51, 15,  34, 56, 7, 9};
    LinkedList<int> test033 = LinkedList<int>(test0331, 11);
    cout <<"test033 = LinkedList<int>(test0331, 11) = ";
    test033.Print();
    LinkedList<int> test07 = * test033.GetSubList(4, 9);
    cout <<"test07 = test033.GetSubList(4, 9) = ";
    test07.Print();
    errors = errors + checkin((test07.GetLength() == 6)," GetSubList(4, 9) ");
    cout << endl;
        

    cout << "#####Тест операций:" << endl;
    test02.Prepend(88);
    cout <<"test02.Prepend(88) = ";
    test02.Print();
    errors = errors + checkin(((test02.GetLength() == 11) && (test02.Get(0) == 88)),
                              " Prepend(88) ");
    cout << endl;
        
    test02.Append(23);
    cout <<"test02.Append(23) = ";
    test02.Print();
    errors = errors + checkin(((test02.GetLength() == 12) && (test02.Get(11) == 23)),
                              " Append(23) ");
    cout << endl;
    
        
    test02.InsertAt(77,5);
    cout <<"test02.InsertAt(77,5) = ";
    test02.Print();
    //test06.Print();
    errors = errors + checkin(((test02.GetLength() == 13) && (test02.Get(5) == 77)),
                              " InsertAt(77,5) ");
    cout << endl;
     
        
    cout <<"test02 = ";
    test02.Print();
    cout <<"test03 = ";
    test03.Print();    LinkedList<int> test08;
    cout <<"test08 = * test02.Concat(& test03) = ";
    test08 = * test02.Concat(& test03);
    test08.Print();
    
    errors = errors + checkin((test08.GetLength() == 20),
                              " Concat(&) ");
    cout << endl;
    
    cout << "Тест LinkedList проведен, количество выявленных ошибок = " << errors <<endl;
    return errors;
}

void Test_ArraySequence()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ArraySequence<int> test00 = ArraySequence<int>();
    cout<< "test00 = ArraySequence<int>() = ";
    test00.Print();
    
    

    ArraySequence<int> test02 = ArraySequence<int>(v,7);
    cout<< "test02 = ArraySequence<int>(v,7) = ";
    test02.Print();
    
    ArraySequence<int> test01 = ArraySequence<int>(v,5);
    cout<< "test01 = ArraySequence<int>(v,5) = ";
    test01.Print();
    
    
    
    
 //   ArraySequence<int> test03 = ArraySequence<int>(12,2);
 //   cout<< "test03 = ArraySequence<int>(12,2) = ";
 //   test03.Print();
    
  //  DynamicArray<int> test04_1 = DynamicArray<int>(12, 3);
  //  ArraySequence<int> test04 = ArraySequence<int>(test02);
  //  cout<< "test04 = ArraySequence<int>(test04_1) = ";
  //  test04.Print();
    
    
    test02.Print();
    cout<< "test02.GetFirst() = ";
    cout<< test02.GetFirst() << endl;
    test02.Print();
    
    
    cout<< "test02.GetLast() = ";
    cout<< test02.GetLast() << endl;
    
    cout<< "test02.Get(3) = ";
    cout<< test01.Get(3) << endl;
    
    cout<< "test02.GetLength() = ";
    cout<< test02.GetLength() << endl;
    
    cout<< "test02.InsertAt(3, 77) = ";
    test02.InsertAt(77,3);
    test02.Print();
    
    test02.Append(99);
    cout<< "test02.Append(99) = ";
    test02.Print();
    
    test01.Prepend(55);
    cout<< "test02.Prepend(55) = ";
    test02.Print();
    }

void Test_LinkedListSequence(){
    
    int v[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int v1[] = {1, 4, 9, -3, 0, 5, 5};
    
    LinkedListSequence<int> test00 = LinkedListSequence<int>();
    cout<< "test00 = LinkedListSequence<int>() = ";
    test00.Print();
    
    LinkedListSequence<int> test01 = LinkedListSequence<int>(v, 9);
    cout<< "test01= LinkedListSequence<int>() = ";
    test01.Print();
    
    
    //test01.Print();
    cout<< "test01.GetFirst() = ";
    cout<< test01.GetFirst() << endl;
    
    cout<< "test01.GetLast() = ";
    cout<< test01.GetLast() << endl;
    
    cout<< "test01.Get(4) = ";
    cout<< test01.Get(4) << endl;
    
    //cout<< "test01.GetSubsequence(4,7) = ";
    //cout<< test01.GetSubsequence(4,7) << endl;

    
    cout<< "test01.GetLenght = ";
    cout<< test01.GetLength() << endl;
    
    
    //test01.Print();
    test01.Append(20);
    cout<< "test01.Append= ";
    //test03.Print();
    test01.Print();
    
    test01.Prepend(9);
    cout<< "test02.Prepend= ";
    test01.Print();
    
    test01.InsertAt(22, 9);
    cout<< "test01.Append= ";
    test01.Print();
    
    LinkedListSequence<int> test_v1 = LinkedListSequence<int>(v1,4);
    //test01.Concat(test_v1);
    //cout<< "test01.Append= ";
    //test01.Print();
    
    LinkedListSequence<int> * test04 = test01.Concat(&test_v1);
    LinkedListSequence<int> test05 = *test04;
    cout << "test03 = * test02 = * test01.Concat(test_v1) = ";
    test05.Print();
    
    LinkedListSequence<int> * test02 = test01.GetSubsequence(4,7);
    LinkedListSequence<int> test03 = *test02;
    cout << "test03 = * test02 = * test01.GetSubsequence(4, 7) = ";
    test03.Print();
    return;
}
