/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:26:36 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:26:37 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

Contact::Contact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& p, const std::string& s)
	: firstName(fn), lastName(ln), nickname(nn), phone(p), secret(s) {}

const std::string& Contact::getFirstName() const { return firstName; }
const std::string& Contact::getLastName() const { return lastName; }
const std::string& Contact::getNickname() const { return nickname; }
const std::string& Contact::getPhone() const { return phone; }
const std::string& Contact::getSecret() const { return secret; }

std::string Contact::summaryCell(const std::string& s) {
	if (s.size() <= 10)
		return s;
	else
		return s.substr(0, 9) + ".";
}

void Contact::printSummaryRow(int index) const {
	std::cout 	<< std::setw(10) << index << '|'
			<< std::setw(10) << summaryCell(firstName) << '|'
			<< std::setw(10) << summaryCell(lastName) << '|'
			<< std::setw(10) << summaryCell(nickname) << '\n';
}

void Contact::printFull() const {
	std::cout 	<< getFirstName() << std::endl
			<< getLastName() << std::endl
			<< getNickname() << std::endl
			<< getPhone() << std::endl
			<< getSecret() << std::endl;
	
}

