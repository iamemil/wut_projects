#include <iostream>
#include "Phone.h"
using namespace std;

// Default Constructor
Phone::Phone() : Brand(nullptr), Model(nullptr)
{
	char temp[9] = "Unknown";
	Brand = new char[strlen(temp)];
	Model = new char[strlen(temp)];
	for (int i = 0; i < strlen(temp); i++)
	{
		Brand[i] = temp[i];
		Model[i] = temp[i];
	}
	Brand[strlen(temp)] = '\0';
	Model[strlen(temp)] = '\0';
	Price = 0;
	Number = 123456789;
	RegisteredPhones += 1;
	messageNum = 0;
};

// Parameterized Constructor
Phone::Phone(const char *_brand,const char *_model, unsigned int _price, unsigned int _number)
{
	Brand = new char[strlen(_brand) + 1];
	for (int i = 0; i < strlen(_brand); i++)
	{
		Brand[i] = _brand[i];
	}
	Brand[strlen(_brand)] = '\0';
	Model = new char[strlen(_model) + 1];
	for (int i = 0; i < strlen(_model); i++)
	{
		Model[i] = _model[i];
	}
	Model[strlen(_model)] = '\0';
	Price = _price;
	Number = _number;
	messageNum = 0;
	RegisteredPhones+=1;
}

// Copy Constructor
Phone::Phone(const Phone& f): Brand(nullptr), Model(nullptr), Number(123456789), messageNum(0)
{
	if (f.Brand && f.Model &&(this!=&f)) {
		
		Brand = new char[strlen(f.Brand) + 1];
		for (int i = 0; i < strlen(f.Brand); i++)
			Brand[i] = f.Brand[i];

		Brand[strlen(f.Brand)] = '\0';
		Model = new char[strlen(f.Model) + 1];
		for (int i = 0; i < strlen(f.Model); i++)
			Model[i] = f.Model[i];

		Model[strlen(f.Model)] = '\0';
		this->Number = f.Number;
		this->Price = f.Price;
		this->messageNum = f.messageNum;
		RegisteredPhones += 1;

	}
	
}


// Assignment Operator
Phone& Phone::operator=(const Phone& p) {
	if (this == &p)
		return *this;
	Brand = NULL;
	delete[] Brand;
	Model = NULL;
	delete[] Model;
	Brand = nullptr;
	Model = nullptr;

	if (p.Brand && p.Model) {
		Brand = new char[strlen(p.Brand) + 1];
		for (int i = 0; i < strlen(p.Brand); i++)
			Brand[i] = p.Brand[i];

		Brand[strlen(p.Brand)] = '\0';
		Model = new char[strlen(p.Model) + 1];
		for (int i = 0; i < strlen(p.Model); i++)
			Model[i] = p.Model[i];

		Model[strlen(p.Model)] = '\0';
		Price = p.Price;
		Number = p.Number;
		messageNum = p.messageNum;
		RegisteredPhones += 1;
	}
}

// Destructor
Phone::~Phone() {
	Brand = NULL;
	delete[] Brand;
	Model = NULL;
	delete[] Model;
}

// Prints information about Phone instance
std::ostream& operator<<(std::ostream& out, const Phone& p) {
	out << "Phone Information" << endl;
	out << "Brand: " << p.Brand << endl;
	out << "Model: " << p.Model << endl;
	out << "Phone Number: " << p.Number << endl;
	out << "Price: " << p.Price << endl;
	out << endl;
	return out;
}

// Phone price decreaser
Phone operator-=(Phone& f1, const unsigned int price) {
	if (f1.Price >= price)
		f1.Price -= price;
	else
		f1.Price = 0;
	return f1;
}


// Phone price compare
bool operator<(Phone& f1, Phone& f2) {
	if (f1.Price < f2.Price)
		return 1;
	else
		return 0;
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
			cout << this->messageOwner[i] << " says: " << this->messages[i] << endl;
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
