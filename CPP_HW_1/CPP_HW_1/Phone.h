#pragma once
#include <string.h>
using namespace std;

class Phone {
private:
	char *Brand = NULL;
	char *Model = NULL;
	unsigned int Number;
	unsigned int Price;
	static unsigned int RegisteredPhones;
	int messageNum;
	unsigned int messageOwner[5];
	char messages[5][20];	
public:
	// Default Constructor
	Phone();
	// Parameterized Constructor
	Phone(const char *Brand,const char *Model, unsigned int Price, unsigned int Number);
	
	// Copy Constructor
	Phone(const Phone&);

	// Assignment Operator
	Phone& operator=(const Phone& p);


	// Prints information about Phone instance
	friend ostream& operator<<(std::ostream& out, const Phone& p);

	// Method to send message to another phone
	void SendMessage(const char * text, Phone& p1);

	// Method to show messages
	void ShowMessages();

	// Friend function to calculate average price of 2 Phones
	friend double AveragePrice(const Phone& p1, const Phone& p2);

	// Shows the number of all registered phones
	friend int RegisteredPhoneCount(const Phone& p1);

	// Decreases the price of Phone
	friend Phone operator-=(Phone& f1, const unsigned int price);

	// Compares if f1 is less than f2. If f1<f2, it returns 1, otherwise 0.
	friend bool operator<(Phone& f1, Phone& f2);

	// Destructor
	~Phone();
};

