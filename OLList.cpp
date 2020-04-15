// OLList.cpp
// ENSF 607  Lab 6 Exercise 1 and 2

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
        delete  doomed_node;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        if (maybe_doomed == 0)
            cout << "Could not find item " << itemA << " in the list" << endl;
        else if (maybe_doomed -> item == itemA){
            doomed_node = maybe_doomed;
            before -> next = doomed_node -> next;
            delete doomed_node;
        }
    }
    // point three


    // the remaining part of this function is missing. As part of exercise B
    // students are supposed to complete the rest of the definition of this function.
}


void OLList::destroy()
{
    
    // this function is not properly designed. As part of the exercise B
    // For exercise B: students are supposed to remove the folloiwng lines and
    // complete the definition of this helper function.
    Node *next;
    while (headM != 0){
        next = headM -> next;
        delete headM;
        headM = next;
    }

//    cout << "OLList::destroy was called but isn't ready for use"
//    << "--program is terminated.\n";
    headM = 0;
}

void OLList::copy(const OLList& source)
{
    // this function is not properly designed. As part of the exercise B
    // For exercise B: students are supposed to remove the folloiwng lines and
    // complete the definition of this helper function.
    
    // The only effect of the next line is to tell the compiler
    // not to generate an "unused argument" warning.  Don't leave it
    // it in your solution.

    if (source.headM == 0){
        headM = 0;
        return;
    }
    else if (source.headM -> next == 0){
        headM = new Node;
        headM -> item = source.headM -> item;
        headM -> next = 0;
    }
    else{
        headM = new Node;
        headM -> item = source.headM -> item;

        Node *temp = headM;
        Node *p = source.headM -> next;
        while (p != 0){
            headM -> next = new Node;
            headM = headM -> next;
            headM -> item = p -> item;
            p = p -> next;
        }
        headM -> next = 0;
        headM = temp;
    }


//    (void) source;
//
//    cout << "OLList::copy was called but isn't ready for use"
//    << "--program is terminated.\n";
//    exit(1);

}


