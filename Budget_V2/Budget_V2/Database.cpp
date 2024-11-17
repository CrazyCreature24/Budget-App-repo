#include <string>
#include "Database.h"
#include "Income.h"
#include "Expense.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// TODO: Be able to open a list of expenses and incomes that have been previously used, so they can make the process quicker



Database::Database()
{
	
}

Database::~Database()
{
	for (auto i : _incomes)
	{
		delete i;
	}

	for (auto i : _expenses)
	{
		delete i;
	}
}

void Database::CreateNewExpense()
{
	system("cls");
	std::string name;
	float amount;

	cout << "Create new expense" << endl;

	do {
		cout << "Name? " << endl;
		cin >> name;
	} while (name.size() > 7);

	do {
		cout << "Amount?" << endl;
		cin >> amount;
	} while (amount <= 0.0f);
	
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
	
	do {
		cout << "Name? " << endl;
		cin >> name;
	} while (name.size() > 7);

	do {
		cout << "Amount?" << endl;
		cin >> amount;
	} while (amount <= 0.0f);

	Income* temp = new Income(name, amount);
	_incomes.push_back(temp);

	DisplayIncomeTable();
	cout << "Income Added!" << endl;
}

void Database::DisplayIncomeTable()
{
	cout << "-----Income Table-----\n";
	cout << "Name\t\tAmount\n";
	_totalIncome = 0.0f;
	for (Income* i : _incomes)
	{
		i->Display();
		cout << endl;
		_totalIncome += i->GetAmount();
	}
	cout << endl;
	cout << "Total Income: " << RoundToTwoDecimals(_totalIncome) << endl;
	cout << "-----End-----" << endl << endl;
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
	cout << "Total Expenses: " << RoundToTwoDecimals(_totalExpenses) << endl;
	cout << "-----End-----" << endl << endl;
}

void Database::DisplayMoneySaved()
{
	cout << "-----Money Saved-----\n";
	cout << "Income:" << RoundToTwoDecimals(_totalIncome) << endl;
	cout << "Expenses: " << RoundToTwoDecimals(_totalExpenses) << endl;
	cout << "Money Saved: " << RoundToTwoDecimals(_totalIncome - _totalExpenses) << endl;
	cout << "-----End-----\n\n";
}

void Database::ExportIncomeTable()
{
	string text = "-----Income Table-----\n";
	text += "Name\tAmount\n";
	for (Income* i : _incomes)
	{
		text += i->GetName() + "\t" + to_string(i->GetAmount()) + "\n";
	}

	text += "Total Income: ";
	text += to_string(RoundToTwoDecimals(_totalIncome));
	text += "\n";
	text += "-----End-----\n\n";
	

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
	text += to_string(RoundToTwoDecimals(_totalExpenses));
	text += "\n";
	text += "-----End-----\n\n";

	ExportToTextFile(text, "Expenses");
	
}

void Database::ExportAmountSaved()
{
	string text;
	text += "-----Money Saved-----\n";
	text += "Income: " +  to_string(RoundToTwoDecimals(_totalIncome)) + "\n";
	text += "Expenses: " + to_string(RoundToTwoDecimals(_totalExpenses)) + "\n";
	text += "Money Saved: " + to_string(RoundToTwoDecimals(_totalIncome - _totalExpenses)) + "\n";
	text += "-----End-----\n\n";
	ExportToTextFile(text, "MoneySaved");
}

void Database::ExportToTextFile(std::string text, std::string filename)
{
	// TODO: Export in a folder with the current date on it
	ofstream file;

	file.open(filename + ".txt");
	//file.open(filename + ".txt", std::ios_base::app); // This allows you to add on to an existing text file
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

float Database::RoundToTwoDecimals(float price)
{
	return roundf(price * 100) / 100;
}




