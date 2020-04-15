//
// Created by toyaokeke on 2020-03-27.
//

#ifndef ENSF_607_ASSIGNMENT_6_LIST_H
#define ENSF_607_ASSIGNMENT_6_LIST_H

struct ListItem{
    int year;
    double flow;
    ListItem(int y, double f){
        year =y;
        flow = f;
    }
    ListItem(){}
};

struct Node{
    ListItem item;
    Node *next;
    Node (){
        next = 0;
    }
};

class FlowList{
public:
    FlowList();
    // Default constructor

    ~FlowList();
    // destructor

    FlowList(const FlowList& source);
    // copy constructor

    FlowList& operator =(const FlowList& rhs);
    // assignment operator

//    void print() const;

    const ListItem& getItem() const;
    // REQUIRES: cursorM != NULL.
    // PROMISES: returns the item to which cursorM is attached to.

    void reset();
    // PROMISES: cursorM is equal to headM.

    bool isOn() const;
    // PROMISES: returns true if cursorM != NULL, otherwise
    // returns false

    const Node* cursor()const;
    // PROMISES: returns cursorM.

    void forward();
    // PROMISES: if cursorM != NULL, moves cursorM to the next.

    void insert(const ListItem&);
    // PROMISES: A node with a copy of itemA is added in a way
    // that preserves the non-decreasing order of flows
    // in nodes. Then, sets cursorM to NULL.

    void remove(int target_year);
    // PROMISES: If a node has an item matching the
    // target_year, list is unchanged and gives a clear message
    // that the target_year (e.g. 2000) Not Found. Otherwise
    // exactly one node with its item.year == itemA.year is
    // removed. Then, sets cursorM to NULL.

    int count ()const;
    // PROMISES: returns the number of nodes in the list.

    void print() const;

    double sum() const;

    double average() const;

    double median() const;

private:
    // always points to the first node in the list.
    Node *headM;

    // Initially is set to NULL, but it may point to any node.
    Node *cursorM;

    void copy(const FlowList& source);

    void destroy();

};
#endif //ENSF_607_ASSIGNMENT_6_LIST_H
