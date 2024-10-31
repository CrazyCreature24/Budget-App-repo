#include "Income.h"
#include <iostream>

using namespace std;

Income::Income() : _name(""), _amount(0.0f)
{
	
}

Income::Income(string name, float amount) : _name(name), _amount(amount)
{
	
}

Income::~Income()
{
	
}

void Income::Display()
{
	cout << _name << "\t\t" << _amount;
}