/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:15 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/06 13:28:16 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "Missing arguments!" << '\n';
		return 0;
	}
	std::string str = av[1];

	for (int i = 0; i < str[i]; i++)
		std::cout << (char)toupper(str[i]);
	std::cout << '\n';
	return (0);
}