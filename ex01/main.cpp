/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:16:17 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:17:09 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
	PhoneBook pb;
	/* print header */
	std::cout << "Commands: " << std::setw(10) << "ADD" << '|'
		<< std::setw(10) << "SEARCH" << '|'
		<< std::setw(10) << "EXIT" << '|' << std::endl;
	while (1)
	{
		std::cout << "Pick between three options ([A]dd, [S]earch, [E]xit): ";
		std::string line;
		std::getline(std::cin, line);

		// transform every user input to uppercases
		std::transform(line.begin(), line.end(), line.begin(), ToUpper());

		/* options */
		if (line == "EXIT" || line == "E") break ;
		else if (line == "SEARCH" || line == "S") {
			pb.printTable();
			if (pb.size == 0) {
				std::cout << "PhoneBook is empty.\n";
				continue ;
			}
			std::cout << "Enter index: ";

			/* read full line with std::getline */
			if (!std::getline(std::cin, line)) {
				std::cout << "EOF detected. Exiting.\n";
				break ;
			}
			/* if epmty line -> reprompt */
			if (line.empty()) {
				std::cout << "Please type a number.\n";
				continue ;
			}
			/* parse number std::istringstream */
			int i;
			std::istringstream iss(line);
			if (!(iss >> i)) {
				std::cout << "Not a number. Try again.\n";
				continue ;
			}
			/* validation of the number */
			const Contact* found = pb.at(i);
			if (found == 0) {
				std::cout << "Invalid index. Try 0.." << (pb.size - 1) << std::endl;
				continue ;
			}
			found->printFull();
			continue ;
		}
		else if (line == "ADD" || line == "A") {
			std::string fn, ln, nn, phone, secret;

			if (!getNoEmptyLine("First Name: ", fn)) break ; // Exit on EOF
			if (!getNoEmptyLine("Last Name: ", ln)) break;
			if (!getNoEmptyLine("Nickname: ", nn)) break;	
			while (true) {
				if (!getNoEmptyLine("Phone: ", phone)) break;
				std::string clean = stripPhoneSeparators(phone); // normalize
				if (!isDigitsWithOptionalPlus(clean)) { // validate noralized
					std::cout << "Wrong format!\n";
					continue ;
				}
				phone = clean; // store normalized
				break ;
			}
			if (!std::cin) break ; // if previous call hit EOF;
			if (!getNoEmptyLine("Secret: ", secret)) break;
			
			/* Add info */
			Contact newContact(fn, ln, nn, phone, secret);
			pb.add(newContact);

			std::cout << "Contact added!\n";
			continue ;
		}
		else
			std::cout << "Unknown command.\n";
	}
	return 0;
}

