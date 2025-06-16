/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:31:33 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/30 15:10:16 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

static std::string	ft_itoa(int n)
{
	std::stringstream	str;

	str << n;
	return (str.str());
}

void	Contact::ft_SetContact(std::string fn, std::string ln, std::string nn, \
	std::string pn, std::string ds)
{
	_first_name = fn;
	_last_name = ln;
	_nickname = nn;
	_phone_number = pn;
	_darkest_secret = ds;
}

void	Contact::ft_DisplayContact(void) const
{
	std::cout << "First Name : " << _first_name << std::endl
			  << "Last Name : " << _last_name << std::endl
			  << "_nickname : " << _nickname << std::endl
			  << "Phone Number : " << _phone_number << std::endl
			  << "Darkest Secret : " << _darkest_secret << std::endl;
}

void	Contact::ft_Tronc(std::string str, bool pipe)
{
	std::string	Sapce;

	if (str.length() > 10)
	{
		std::cout << std::setw(9) << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
	if (pipe)
		std::cout << "|";
	else
		std::cout << std::endl;
}

void	Contact::ft_SearchDisplay(int index)
{
	ft_Tronc(ft_itoa(index), true);
	ft_Tronc(_first_name, true);
	ft_Tronc(_last_name, true);
	ft_Tronc(_nickname, false);
}
