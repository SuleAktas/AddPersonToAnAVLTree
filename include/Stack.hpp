#ifndef STACK_HPP
#define STACK_HPP
#include<cmath>
#include<iostream>
using namespace std;
#include "ElemanYok.hpp"
class Stack
{
private:
	char * elemanlar;
	int stackBasi;
	int elemanSayisi;
	int kapasite;


	bool dolumu();

	void yerAc(int boyut);
	
public:
	Stack();

	bool isEmpty() const;

	void push(const char &eleman);
	
	void pop() throw(ElemanYok);

	void Pop_Elemanlari_Goster();
	
	const char& top()const throw(ElemanYok);
	
	void makeEmpty();

	~Stack();
};
#endif