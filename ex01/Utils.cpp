/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:27:42 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:27:43 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <iostream>
#include <cctype>
#include <string>

/* --- input helpers --- */
bool getLineOrEof(const std::string &prompt, std::string& out) {
	std::cout << prompt;
	if (!std::getline(std::cin, out))
		return false; //EOF or stream err
	return true;
}

bool getNoEmptyLine(const std::string &prompt, std::string& out) {
	while (true) {
		if (!getLineOrEof(prompt, out)) // EOF, caller handles exit
			return false;
		if (!out.empty())
			return true;
		std::cout << "Cannot be empty!\n";
	}
}

/* --- validation + formating --- */
bool isAllDigits(const std::string &s) {
	if (s.empty()) return false;
	for (std::string::size_type i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

bool isDigitsWithOptionalPlus(const std::string &s) {
	if (s.empty()) return false;
	if (s[0] == '+')
		return isAllDigits(s.substr(1));
	return isAllDigits(s);
}

std::string stripPhoneSeparators(const std::string& s) {
	std::string result;
	std::string::size_type startIndex = 0;
	bool keepPlus = (s.size() > 0 && s[0] == '+');
	if (keepPlus) {
		startIndex = 1;
		result.push_back('+');
	}
	for (std::string::size_type i = startIndex; i < s.size(); ++i) {
		char c = s[i];
		if (c == ' ' || c == '-' || c == '(' || c == ')' || c == '+')
			continue ; // skip separators and extra '+'
		result.push_back(c);
	}
	return result;
}

/* --- uppercase functor --- */
char ToUpper::operator()(char c) const {
	return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

