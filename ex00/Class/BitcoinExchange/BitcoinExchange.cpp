/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/18 13:46:50 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

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

void	BitcoinExchange::addData(std::string date, float value)
{
	
}

std::string	BitcoinExchange::splitLineDate(std::string line)
{
	std::string date;
	for(size_t i = 0; i< line.size(); ++i)
	{
		if(line[i] == '-' || line[i] == '|')
			break;
		date += line[i];
	}
	return date;
}

float BitcoinExchange::splitLineValue(std::string line)
{
	std::string value;
	bool delimiterFound = false;
	for(size_t i = 0; i < line.size(); ++i)
	{
		if(line[i] == '|')
		{
			delimiterFound = true;
			continue;
		}
		if(delimiterFound)
			value += line[i];
	}
	return atof(value.c_str());
}

void	BitcoinExchange::checkFormat(std::string line)
{
	std::istringstream iss(line);
	std::string dateString, valueString, delimiter;
	std::getline(iss, dateString, '-');
	if(dateString.empty() || dateString.find_first_not_of("0123456789"))
		throw BitcoinExchange::BadDateFormatException();
	std::getline(iss, delimiter, '-');
	if(delimiter != "-")
		throw BitcoinExchange::BadDateFormatException();
	std::getline(iss, dateString, '|');
	if(dateString.empty() || dateString.find_first_not_of("0123456789-"))
		throw BitcoinExchange::BadLineFormatException();
	std::getline(iss, valueString);
	if(valueString.empty() || valueString.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::BadValueException();
	return;
}

// ----------Non_Members_Functions----------


