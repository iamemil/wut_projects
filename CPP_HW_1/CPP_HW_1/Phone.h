#pragma once
#include <string.h>
using namespace std;

class Phone {
private:
	char Brand[30];
	char Model[40];
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
	Phone(const char Brand[10],const char Model[15], unsigned int Price, unsigned int Number);
	
	// Prints information about Phone instance
	void Print() const;

	// Method to send message to another phone
	void SendMessage(const char * text, Phone& p1);

	// Method to show messages
	void ShowMessages();

	// Friend function to calculate average price of 2 Phones
	friend double AveragePrice(const Phone& p1, const Phone& p2);

	// Shows the number of all registered phones
	friend int RegisteredPhoneCount(const Phone& p1);

};
