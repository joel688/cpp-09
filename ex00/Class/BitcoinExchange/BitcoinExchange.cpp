/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/18 11:22:41 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"
#include <fstream>

// ----------Constructors----------

BitcoinExchange::BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	return;
}

// ----------Deconstructors----------

BitcoinExchange::~BitcoinExchange()
{
	return;
}

// ----------Setters----------

// ----------Getters----------

// ----------Operators_Overloaders----------

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	return(*this);
}

// ----------Members_Functions----------

void BitcoinExchange::parseCsv(std::ifstream inputFile)
{
	std::string line;
	if(!inputFile.is_open())
		throw BitcoinExchange::NoArgFileException();
	while(!inputFile.eof())
	{
		std::getline(inputFile, line);
		this->checkFormat(line);
		this->addData(splitLineDate(line), splitLineValue(line));
	}
	inputFile.close();
}

std::string	BitcoinExchange::splitLineDate(std::string line)
{
	return;	
}


void	BitcoinExchange::checkFormat(std::string line)
{
	
	return;
}
// ----------Non_Members_Functions----------


