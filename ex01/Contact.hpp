#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	/* Private data - cannot be accessed directly from outside this class */
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
