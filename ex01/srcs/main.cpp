/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:36:09 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/28 16:11:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

static inline bool	ft_IsOk(std::string str)
{
	bool	test = true;
	for(std::string::size_type i = 0; i < str.length() && test; i++)
	{
		if (!isspace(str[i]) && isprint(str[i]))
			test = false;
	}
	if (test)
		return (true);
	return (str.find("\033[A") != std::string::npos ||	// Up
			str.find("\033[B") != std::string::npos ||	// Down
			str.find("\033[C") != std::string::npos ||	// Right
			str.find("\033[D") != std::string::npos);	// Left
}

static inline bool	ft_IsDigit(std::string str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
		{
			return (false);
		}
	}
	return (true);
}

static inline std::string	ft_trim(std::string str)
{
	size_t	first_char = str.find_first_not_of(' ');
	size_t	last_char;

	if (first_char == std::string::npos)
	{
		return ("");
	}
	last_char = str.find_last_not_of(' ');
	return (str.substr(first_char, last_char - first_char + 1));
}

static inline bool	ft_new(PhoneBook &PhBo)
{
	std::string	tmp[5];
	std::string	msg[5] = {"First Name : ", "Last Name : ", "Nickname : ",
		"Phone Number : ", "Darkest Secret : "};
	Contact		cont;
	int			i;
	
	for (i = 0; i < 5; i++)
	{
		std::cout << msg[i];
		std::getline(std::cin, tmp[i]);
		if (std::cin.eof())
			return (false);
		tmp[i] = ft_trim(tmp[i]);
		if (i != 3)
		{
			if (ft_IsOk(tmp[i]))
			{
				std::cout << "Fields must be filled with printable charracter"
						  << "and cannot contain only spaces." << std::endl;
				return (false);
			}
		}
		else
		{
			if (!ft_IsDigit(tmp[i]))
			{
				std::cout << "Invalid input: Phone Number must be numeric" 
						  << std::endl;
				return (false);
			}
		}
	}
	cont.ft_SetContact(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
	PhBo.ft_AddContact(cont);
	return (true);
}

int	main(void)
{
	PhoneBook	PhBo;
	std::string	command;

	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << "\nCtrl D pressed : exit the programe" << std::endl;
			break ;
		}
		std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			if (!ft_new(PhBo))
			{
				if (!std::cin.eof())
					std::cin.clear();
			}
		}
		else if (command == "SEARCH")
		{
			PhBo.ft_Search();
		}
		else if (command == "EXIT")
		{
			break ;
		}
		std::cout << std::endl;
	}
	return (0);
}
