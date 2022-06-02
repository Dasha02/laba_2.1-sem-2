

#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "Tests.hpp"

using namespace std;


int main(int argc, const char * argv[]) {

   // int i;
    Test_DynamicArray();
    cout<<"****************************************************************************************"<<endl;
    Test_LinkedList();
    cout<<"****************************************************************************************"<<endl;
    Test_ArraySequence();
    //cout<<"****************************************************************************************"<<endl;
    //Test_LinkedListSequence();
    cout<<"****************************************************************************************"<<endl;
    return 0;
}
