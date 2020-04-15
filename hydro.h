//
// Created by toyaokeke on 2020-03-27.
//

#ifndef ENSF_607_ASSIGNMENT_6_HYDRO_H
#define ENSF_607_ASSIGNMENT_6_HYDRO_H

#include "list.h"


void displayHeader();

int readData(FlowList&);

int menu();

void display(const FlowList&);

void addData(FlowList&);

void removeData(FlowList&);

double average(const FlowList&);

double median(const FlowList&);

void saveData(FlowList&);

void pressEnter();

#endif //ENSF_607_ASSIGNMENT_6_HYDRO_H
