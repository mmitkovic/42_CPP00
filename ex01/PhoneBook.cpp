#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

PhoneBook::PhoneBook() : next(0), size(0) {}

void PhoneBook::add(const Contact& c) {
	contacts[next] = c; // store at current index
	next = (next + 1) % 8; // move to next position (wrap around at 8)
	size = std::min(size + 1, 8); // increase size, max out at 8
}

void PhoneBook::printTable() const {
	std::cout << std::setw(10) << "INDEX" << '|'
		<< std::setw(10) << "FIRST NAME" << '|'
		<< std::setw(10) << "LAST NAME" << '|'
		<< std::setw(10) << "NICKNAME" << std::endl;
	for (int i = 0; i < size; i++) {
		contacts[i].printSummaryRow(i);
	}
}

const Contact* PhoneBook::at(int index) const {
	if (index < 0 || index >= size) return NULL;
	return &contacts[index];
}

