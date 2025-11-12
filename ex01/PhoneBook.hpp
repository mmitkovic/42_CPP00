/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:27:34 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:27:35 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int next; // updtae
public:
	PhoneBook(); // sets next=0, size=0
	void add(const Contact& c);
	void printTable() const;
	const Contact* at(int index) const;
	int size; // number os stored contacts (max 8)
};

#endif
