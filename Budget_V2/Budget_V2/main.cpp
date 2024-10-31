#include "Expense.h"
#include "Income.h"
#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

// TODO: Be able to open previous months


Database* g_data;

void Init();

void Expenses();

void Income();


int main()
{
	Init();

	cout << "Welcome to the budget app!\nWhat would you like to do?\n";
	
	char choice;

	do
	{
		cout << "1) Look at Income\n2) Look at Expenses\n0) Quit\n";
		cin >> choice;

		while (choice < '0' || choice > '2')
		{
			cout << "Invalid choice, try again\n";
			cin >> choice;
		}

		switch (choice)
		{
		case '1':
			Income();
			break;
		case '2':
			Expenses();
			break;
		default:
			break;
		}

		system("cls");

	} while (choice != '0');

}

void Init()
{
	g_data = new Database;
}

void Expenses()
{
	char choice;

	do
	{
		system("cls");
		g_data->DisplayExpenseTable();

		cout << "1) Add an Expense\n2) Export Expense Table\n0) Back\n";
		cin >> choice;

		while (choice < '0' || choice > '2')
		{
			cout << "Invalid choice, try again\n";
			cin >> choice;
		}

		switch (choice)
		{
		case '1':
			g_data->CreateNewExpense();
			break;
		case '2':
			g_data->ExportExpenseTable();
			cout << "File Exported" << endl;
			system("pause");
			break;
		default:
			break;
		}

	} while (choice != '0');
}

void Income()
{
	char choice;

	do
	{
		system("cls");
		g_data->DisplayIncomeTable();

		cout << "1) Add an Income\n2) Export Income Table\n0) Back\n";
		cin >> choice;

		while (choice < '0' || choice > '2')
		{
			cout << "Invalid choice, try again\n";
			cin >> choice;
		}

		switch (choice)
		{
		case '1':
			g_data->CreateNewIncome();
			break;
		case '2':
			g_data->ExportIncomeTable();
			cout << "File Exported" << endl;
			system("pause");
			break;
		default:
			break;
		}

	} while (choice != '0');
}
