/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/20 15:37:27 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"
#include <sstream>
#include <string>

// ----------Constructors----------

BitcoinExchange::BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
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
	this->_CsvParsed = src._CsvParsed;
	return(*this);
}

// ----------Members_Functions----------

void BitcoinExchange::parseCsv(std::ifstream &inputFile)
{
	std::string line;
	const char delimiter = '|';
	if(!inputFile.is_open())
		throw BitcoinExchange::NoArgFileException();
	while(std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		std::istringstream iss(line);
		std::cout << line << std::endl;
		std::string date, value;
		std::getline(iss, date, delimiter);
		std::cout << date << std::endl;
		std::getline(iss, value, delimiter);
		std::cout << value << std::endl;
		this->addData(date, std::atof(value.c_str()));
	}
	inputFile.close();
}

void	BitcoinExchange::addData(std::string date, float value)
{
	this->_CsvParsed.insert(std::map<std::string, float>::value_type(date, value));
}

std::string	BitcoinExchange::splitLineDate(const std::string &line)
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

float BitcoinExchange::splitLineValue(const std::string &line)
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

const std::string BitcoinExchange::NoArgFileException::err() const throw()
{
	return("Error: Bad arg.");
}

const std::string BitcoinExchange::BadLineFormatException::err() const throw()
{
	return("Error: Bad Line Format.");
}

const std::string BitcoinExchange::BadDateFormatException::err() const throw()
{
	return("Error: Bad Date.");
}

const std::string BitcoinExchange::BadValueException::err() const throw()
{
	return("Error: Bad Value.");
}
// ----------Non_Members_Functions----------


