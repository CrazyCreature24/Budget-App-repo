//This class will be the center to all the incomes and expenses
#include <vector>

enum class TransactionType
{
	ExpenseType,
	IncomeType,
	Both,
	Num
};


class Expense;
class Income;

class Database
{
	public:
		Database();
		~Database();

		void CreateNewExpense();
		void CreateNewIncome();

		void DisplayIncomeTable();
		void DisplayExpenseTable();

		void ExportIncomeTable();
		void ExportExpenseTable();

		void ExportToTextFile(std::string text, std::string filename);
		void OpenFile(const char* filename);

	protected:
		std::vector<Expense*> _expenses;
		float _totalExpenses = 0.0f;

		std::vector<Income*> _incomes;
		float _totalIncome = 0.0f;
		
};