 // lab6Ex1.cpp
// 
// ENSF 607 Lab 6 Exercise 1 and 2
//

#include <iostream>
using namespace std;

#include "OLList.h"

int main()
{
    OLList the_list;
    OLList empty_list(the_list);

    cout << "List just after creation: ";
    the_list.print();

    cout << "Empty list just after creation: ";
    empty_list.print();

    the_list.insert(330);

    OLList one_item_list(the_list);
    cout << "One item list just after creation: ";
    one_item_list.print();

    the_list.insert(440);
    the_list.insert(220);
    the_list.insert(110);

    OLList many_item_list(the_list);
    cout << "Many item list just after creation: ";
    many_item_list.print();

    cout << "List after some insertions: ";
    the_list.print();
    the_list.remove(550);
    the_list.remove(330);
    cout << "List after some removals: ";
    the_list.print();
    cout << "Re-assigning many item list: ";
    many_item_list = the_list;
    many_item_list.print();


    return 0;
}
