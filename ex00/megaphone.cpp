/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:28:15 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/11/14 14:59:16 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 0;
	}
	std::string str;

	for (int i = 1; i < ac; i++)
	{
		str = av[i];
		for (int j = 0; j < str[j]; j++)
		{
			std::cout << (char)toupper(str[j]);
		}
	}
	std::cout << '\n';
	return (0);
}
