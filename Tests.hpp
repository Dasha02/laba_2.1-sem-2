//
//  Tests.hpp
//  Laba02_Sem02_Ver_02
//
//  Created by Олег Пархоменко on 22.05.2022.
//

#ifndef Tests_h
#define Tests_h

#include <stdio.h>
#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"

using namespace std;

int chekin (bool check, string message);
int Test_DynamicArray ();
int Test_LinkedList();
void Test_ArraySequence();
void Test_LinkedListSequence();
#endif /* Tests_h */
