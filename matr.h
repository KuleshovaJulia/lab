#pragma once

class Set
{
private:
	int *mass, size;
public: 
	//Set() : size(0), mass(new int[0]) {};// конструктор
	Set()
	{
	    mass = 0;
		size = 0;
	}
	Set(const Set&) {};// конструктор копирования
	~Set() // деструктор
	{ 
		delete[] mass;
	}
	void add(int number);
	void display();
	void checksize();
	void del(int number);
	int sum();
	int otric();
	int ravn(Set* temp);
	
};
