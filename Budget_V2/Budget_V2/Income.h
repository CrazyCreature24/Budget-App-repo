#include <string>

class Income
{
	public:
		Income();
		Income(std::string name, float amount);
		~Income();
		
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