#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8]; // Fixed-size array of 8 Contacts objects
	int next; // Index where the next contact will be stored
public:
	PhoneBook(); // sets next=0, size=0
	void add(const Contact& c);
	void printTable() const;
	const Contact* at(int index) const;
	int size; // number os stored contacts (max 8)
};

#endif
