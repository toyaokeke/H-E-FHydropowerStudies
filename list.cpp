//
// Created by toyaokeke on 2020-03-27.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
        : headM(0), cursorM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

int FlowList::count() const {
    int count = 0;
    for (const Node *temp = headM; temp != 0; temp = temp -> next)
        count++;
    return count;
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

const ListItem& FlowList::getItem() const {
    if (isOn())
        return cursorM ->item;
    else
        return headM -> item;
}

void FlowList::reset() {
    cursorM = headM;
}

bool FlowList::isOn() const {
    return cursorM != 0;
}

const Node* FlowList::cursor() const {
    return cursorM;
}

void FlowList::forward() {
    if (isOn())
        cursorM = cursorM -> next;
}

void FlowList::print() const {
    cout << "Year" << "\t" << "Flow (in billions of cubic meters)" << endl;
    if (headM != 0) {
        cout << headM -> item.year << "\t" << headM -> item.flow << endl;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << p -> item.year << "\t" << p -> item.flow << endl;
    }
    cout << "The annual average of the flow is: " << average() << " billions of cubic meters" << endl;
    cout << "The median flow is: " << median() << " billions of cubic meters" << endl;
}

double FlowList::sum() const {
    double sum = 0.0;
    for (const Node *temp = headM; temp != 0; temp = temp -> next)
        sum = sum + temp -> item.flow;
    return sum;
}

double FlowList::average() const {
    if (count() == 0)
        return 0.0;
    return sum() / count();
}

double FlowList::median() const {
        if (count() == 0)
            return 0.0;
        else if (count() % 2 != 0){
            Node *temp = headM;
            int pos = 0;
            while (pos < count() / 2){
                temp = temp -> next;
                pos++;
            }
            return temp -> item.flow;
        }
        else{
            Node *temp = headM;
            int pos = 0;
            while (pos < count() / 2 - 1){
                temp = temp -> next;
                pos++;
            }
            return (temp -> item.flow + temp -> next ->item.flow) / 2;
        }
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == 0 || itemA.flow < headM->item.flow ) {
        new_node->next = headM;
        headM = new_node;
        cursorM = 0;
        cout << "New record inserted successfully" << endl;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA.flow > after->item.flow) {
            before = after;
            after = after->next;
        }
        if (after == 0){
            if (before -> item.flow == itemA.flow && before -> item.year == itemA.year)
                cout << "Error: duplicate data" << endl;
            else{
                new_node->next = after;
                before->next = new_node;
                cursorM = 0;
                cout << "New record inserted successfully" << endl;
            }
        }
        else{
            if ((before -> item.flow == itemA.flow && before -> item.year == itemA.year) ||
                (after -> item.flow == itemA.flow && after -> item.year == itemA.year)){
                cout << "Error: duplicate data" << endl;
            }
            else{
                new_node->next = after;
                before->next = new_node;
                cursorM = 0;
                cout << "New record inserted successfully" << endl;
            }
        }
    }
}

void FlowList::remove(int target_year)
{
    // if list is empty, do nothing
    if (headM == 0){
        cout << "Error: No such data" << endl;
        return;
    }

    Node *doomed_node = 0;

    if (target_year == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
        delete  doomed_node;
        cursorM = 0;
        cout << "Record was successfully removed" << endl;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && target_year != maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        if (maybe_doomed == 0)
            cout << "Error: No such data" << endl;
        else{
            doomed_node = maybe_doomed;
            before -> next = doomed_node -> next;
            delete doomed_node;
            cursorM = 0;
            cout << "Record was successfully removed" << endl;
        }
    }
}


void FlowList::destroy()
{
    Node *next;
    while (headM != 0){
        next = headM -> next;
        delete headM;
        headM = next;
    }

    headM = 0;
    cursorM = 0;
}

void FlowList::copy(const FlowList& source)
{
    cursorM = 0;

    if (source.headM == 0){
        headM = 0;
        return;
    }
    else if (source.headM -> next == 0){
        headM = new Node;
        ListItem item(source.headM -> item.year, source.headM -> item.flow);
        headM -> item = item;
        headM -> next = 0;
    }
    else{
        headM = new Node;
        ListItem item(source.headM -> item.year, source.headM -> item.flow);
        headM -> item = item;

        Node *temp = headM;
        Node *p = source.headM -> next;
        while (p != 0){
            headM -> next = new Node;
            headM = headM -> next;
            ListItem item(p -> item.year, p -> item.flow);
            headM -> item = item;
            p = p -> next;
        }
        headM -> next = 0;
        headM = temp;

    }

}

