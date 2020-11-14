#ifndef __Node_h__
#define __Node_h__

#include<iostream>
using namespace std;
typedef int elemtype;

class Node
{
public:
	Node* next;
	elemtype data;
};

#endif//_Node_h__