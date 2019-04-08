#include <iostream>
#include "Phone.h"
using namespace std;

// Default Constructor
Phone::Phone() {
	strcpy_s(Brand, "Unknown");
	strcpy_s(Model, "Unknown");
	Price = 0;
	Number = 123456789;
	RegisteredPhones += 1;
	messageNum = 0;
};

// Parameterized Constructor
Phone::Phone(const char _brand[10],const char _model[15], unsigned int _price, unsigned int _number)
{
	strcpy_s(Brand, _brand);
	strcpy_s(Model, _model);
	Price = _price;
	Number = _number;
	messageNum = 0;
	RegisteredPhones+=1;
}

// Prints information about Phone instance
void Phone::Print() const {
	cout << "Phone Information" << endl;
	cout << "Brand: " << Brand << endl;
	cout << "Model: " << Model << endl;
	cout << "Phone Number: " << Number << endl;
	cout << "Price: " << Price << endl;
	cout << endl;
}

// Method to send message to another phone
void Phone::SendMessage(const char* text, Phone& p1) {
	p1.messageOwner[p1.messageNum] = this->Number;
	strcpy_s(p1.messages[p1.messageNum], text);
	p1.messageNum += 1;
	p1.ShowMessages();
}

// Method to show messages
void Phone::ShowMessages() {
	cout << "Received messages of " << this->Number << endl;
	if (messageNum) {
		for (int i = 0; i < this->messageNum; i++)
		{
			cout << this->messageOwner[i] << " says: " << this->messages[i] << endl;
		}
	}
	else
		cout << "No messages !" << endl;
	cout << endl;
}

// Friend function to calculate average price of 2 Phones
double AveragePrice(const Phone& p1, const Phone& p2) {
	return (p1.Price + p2.Price) / 2;
}

// Shows the number of all registered phones
int RegisteredPhoneCount(const Phone& p1) {
	return p1.RegisteredPhones;
}
