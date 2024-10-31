#include "Expense.h"
#include <iostream>

using namespace std;

Expense::Expense() : _name(""), _amount(0.0f)
{
	
}

Expense::Expense(string name, float amount) : _name(name), _amount(amount)
{
	
}

Expense::~Expense()
{
	
}

void Expense::Display()
{
	cout << _name << "\t\t" << _amount;
}