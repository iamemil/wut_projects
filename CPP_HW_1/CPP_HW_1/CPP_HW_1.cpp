#include <iostream>
#include <string.h>
#include "Phone.h"
using namespace std;

unsigned int Phone::RegisteredPhones = 0;

int main()
{
	
	// Instance with the help of parameterized constructor
	Phone a1("Apple", "iPhone 7", 650, 450010623);
	Phone a2("Samsung", "Galaxy S10", 890, 374240625);
	// Instance with the help of default constructor
	Phone a3;
	// Class method to print information about instance
	a1.Print();
	a2.Print();
	a3.Print();

	// Friend function to print average price of two phones
	cout << "Average price of two phones is " << AveragePrice(a1,a2) << '$' << endl;

	// Friend function to print number of registered phones
	cout << "Registered phones - " << RegisteredPhoneCount(a1) << endl;
	cout << endl;


	// Sending "Hello !" from a2 to a3
	a2.SendMessage("Hello !", a3);

	// Sending "Hello !" from a1 to a2
	a1.SendMessage("How are you ?", a2);

	// Showing received messages of a3
	a3.ShowMessages();

	// Showing received messages of a1 (no messages)
	a1.ShowMessages();
}

