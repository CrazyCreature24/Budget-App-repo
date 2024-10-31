#include <string>

class Expense
{
	public:
		Expense();
		Expense(std::string name, float amount);
		~Expense();

		void Display();

		//Setters
		void SetName(std::string n) { _name = n; }
		void SetAmount(float a) { _amount = a; }

		//Getters
		std::string GetName() { return _name; }
		float GetAmount() { return _amount; }

	protected:
		std::string _name;
		float _amount;
};