#include <string>
#include "Database.h"
#include "Income.h"
#include "Expense.h"
#include <iostream>
#include <fstream>

using namespace std;

// TODO: Be able to open a list of expenses and incomes that have been previously used, so they can make the process quicker



Database::Database()
{
	
}

Database::~Database()
{
	
}

void Database::CreateNewExpense()
{
	system("cls");
	std::string name;
	float amount;

	cout << "Create new expense" << endl;
	cout << "Name? " << endl;
	cin >> name;
	cout << "Amount?" << endl;
	cin >> amount;
	
	Expense* temp = new Expense(name, amount);
	_expenses.push_back(temp);

	DisplayExpenseTable();
	cout << "Expense Added!" << endl;
}

void Database::CreateNewIncome()
{
	system("cls");
	std::string name;
	float amount;

	cout << "Create new income" << endl;
	cout << "Name? " << endl;
	cin >> name;
	cout << "Amount?" << endl;
	cin >> amount;

	Income* temp = new Income(name, amount);
	_incomes.push_back(temp);

	DisplayIncomeTable();
	cout << "Income Added!" << endl;
}

void Database::DisplayIncomeTable()
{
	cout << "-----Income Table-----\n";
	cout << "Name\t\tAmount\n";
	for (Income* i : _incomes)
	{
		i->Display();
		cout << endl;
	}
	cout << endl;
}

void Database::DisplayExpenseTable()
{
	cout << "-----Expense Table-----\n";
	cout << "Name\t\tAmount\n";
	_totalExpenses = 0.0f;
	for (Expense* i : _expenses)
	{
		i->Display();
		cout << endl;
		_totalExpenses += i->GetAmount();
	}
	
	cout << endl;
	cout << "Total Expenses: " << _totalExpenses << endl;

}

void Database::ExportIncomeTable()
{
	string text = "-----Income Table-----\n";
	text += "Name\tAmount\n";
	for (Income* i : _incomes)
	{
		text += i->GetName() + "\t" + to_string(i->GetAmount()) + "\n";
	}

	ExportToTextFile(text, "Incomes");
	
}

void Database::ExportExpenseTable()
{
	string text = "-----Expense Table-----\n";
	text += "Name\tAmount\n";
	for (Expense* i : _expenses)
	{
		text += i->GetName() + "\t" + to_string(i->GetAmount()) + "\n";
	}

	text += "Total Expenses: ";
	text += to_string(_totalExpenses);
	text += "\n";

	ExportToTextFile(text, "Expenses");
	
}

void Database::ExportToTextFile(std::string text, std::string filename)
{
	// TODO: Export in a folder with the current date on it
	ofstream file;

	file.open(filename + ".txt", std::ios_base::app);
	file << text;
}

void Database::OpenFile(const char* filename)
{
	// TODO: Open file via enum? Or even better, open directory and be able to choose

	ifstream file;
	string text;

	file.open(filename);
	getline(file, text);

	if (text == "")
	{
		cout << "There is no data in file" << endl;
	}
	else
	{
		cout << "File contains: " << endl;
		cout << text;
	}
}




