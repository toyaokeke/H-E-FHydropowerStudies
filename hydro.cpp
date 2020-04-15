//
// Created by toyaokeke on 2020-03-27.
//
#include <iostream>
#include <fstream>
#include <string>
#include "hydro.h"
#include "list.h"
using namespace std;

void displayHeader(){
    cin.clear();
    fflush(stdin);

    cout << "HEF Hydropower Studies - Winter 2020" << endl;
    cout << "Program: Flow Studies" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: B01" << endl;
    cout << "Instructor: Mohammad Moshirpour" << endl;
    cout << "Teaching Assistant(s): Fatemeh Sharifi, Masoud Karimi Fatemi" << endl;
    cout << "Produced By: Toya Okeke\n" << endl;
    pressEnter();

    cin.clear();
    fflush(stdin);
}

void addData(FlowList& list){
    int year;
    double flow;

    cin.clear();
    fflush(stdin);
    cout << "Please enter a year: ";
    cin >> year;

    cin.clear();
    fflush(stdin);
    cout << "Please enter the flow: ";
    cin >> flow;

    ListItem item(year, flow);
    list.insert(item);

    cin.clear();
    fflush(stdin);
}

void pressEnter(){
    cin.clear();
    fflush(stdin);

    while (true){
        cin.clear();
        fflush(stdin);
        cout << "<<< Press Enter to Continue >>>" << endl;
        if (cin.get() == '\n')
            break;
    }
    cin.clear();
    fflush(stdin);
}

void removeData(FlowList& list){
    int year;

    cin.clear();
    fflush(stdin);
    cout << "Please enter the year that you want to remove: ";
    cin >> year;

    list.remove(year);

    cin.clear();
    fflush(stdin);
}

double average(const FlowList& list){
    return list.average();
}

double median(const FlowList& list){
    return list.median();
}

int readData(FlowList& list){
    cin.clear();
    fflush(stdin);
    string base = "flow.txt";
//    string folder;
//    cout << "Where is folder.txt located?" << endl;
//    cout << "For Windows, folder format should be drive:\\\\mydirectory\\\\" << endl;
//    cout << "For Mac, folder format should be drive:/mydirectory/" << endl;
//    cin >> folder;
//
//    string inFile = folder + base;
    ifstream inObj;
//    inObj.open(inFile);
    inObj.open(base);

    if (!inObj) {
        cerr << "Unable to open file " << base;
        exit(1);   // call system to stop
    }

    int year;
    double flow;
    while (inObj >> year >> flow){
        ListItem item(year, flow);
        list.insert(item);
    }
    inObj.close();
    cin.clear();
    fflush(stdin);
    return list.count();
}

void saveData(FlowList& list){
    cin.clear();
    fflush(stdin);

    string base = "flow_saved.txt";
//    string folder;
//    cout << "Where would you like to save your file? Note that existing files will be overwritten." << endl;
//    cout << "For Windows, folder format should be drive:\\\\mydirectory\\\\" << endl;
//    cout << "For Mac, folder format should be drive:/mydirectory/" << endl;
//    cin >> folder;
//
//    string outFile = folder + base;
    ofstream  outObj;
//    outObj.open(outFile, ios::out | ios::trunc);
    outObj.open(base, ios::out | ios::trunc);

    if (!outObj) {
        cerr << "Unable to open file " << base;
        exit(1);   // call system to stop
    }

    list.reset();
    while(list.cursor() != 0){
        outObj << list.getItem().year << "\t" << list.getItem().flow << endl;
        list.forward();
    }
    cout << "Data was successfully saved to " << base << endl;
    outObj.close();
    cin.clear();
    fflush(stdin);
}



int menu(){
    int option;
    cout << "Please select one of the following options" << endl;
    cout << "1. Display flow list, average and median" << endl;
    cout << "2. Add data" << endl;
    cout << "3. Save data into the file" << endl;
    cout << "4. Remove data" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice (1, 2, 3, 4, of 5):" << endl;
    cin >> option;
    return option;
}

void display(const FlowList& list){
    cin.clear();
    fflush(stdin);

    list.print();

    cin.clear();
    fflush(stdin);
}

int main(void) {
    FlowList x;
    int numRecords;
    displayHeader();
    numRecords = readData(x);
    int quit = 0;

    while(1){
        switch(menu()){
            case 1:
                display(x);
                pressEnter();
                break;
            case 2:
                addData(x);
                pressEnter();
                break;
            case 3:
                saveData(x);
                pressEnter();
                break;
            case 4:
                removeData(x);
                pressEnter();
                break;
            case 5:
                cout << "\nProgram terminated!\n\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n";
                pressEnter();
        }
        if(quit == 1) break;
    }

    // Creating a copy of FlowList x called copy1
    FlowList copy1;
    copy1 = x;
    // In the following section call addData to add
    // following records (year, flow) to copy1:
    // 2012 459.99
    // 2013 2000.34
    addData(copy1);
    // Use the following code to create a copy of copy1 called copy2
     FlowList copy2 = copy1;

    // removing three records from copy2
    copy2.remove(1922);
    copy2.remove(2003);
    copy2.remove(2001);

// Display the values in three list copy 2, copy1, and x
    cout << "\n values in copy2 are: " << endl;
    display(copy2);

    cout << "\n values in copy1 are: " << endl;
    display(copy1);

    cout << "\n values in x are: " << endl;
    display(x);
    return 0;
}