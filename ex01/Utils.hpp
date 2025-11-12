/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:27:55 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:27:56 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

// input helpers
bool getLineOrEof(const std::string& prompt, std::string& out);
bool getNoEmptyLine(const std::string& prompt, std::string& out);

// validation + formating
bool isAllDigits(const std::string& s);
bool isDigitsWithOptionalPlus(const std::string& s);
std::string stripPhoneSeparators(const std::string& s);

// uppercasing functor
struct ToUpper {
	char operator()(char c) const;
};

#endif
