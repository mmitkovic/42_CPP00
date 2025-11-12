/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:26:28 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:26:31 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phone;
	std::string	secret;
public:
	Contact(); // default ctor

	Contact(const std::string& fn,
	 	const std::string& ln,
	 	const std::string& nn,
	 	const std::string& p,
	 	const std::string& s);

	// getters
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickname() const;
	const std::string& getPhone() const;
	const std::string& getSecret() const;

	// printing
	void	printSummaryRow(int index) const;	
	void	printFull() const;

	// helpers
	static std::string summaryCell(const std::string& s);
};

#endif
