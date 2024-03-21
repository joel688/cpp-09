/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/21 17:43:28 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ne pass pas le test si pas de pipe ou value ou espace a la place de precedemment cite
// try catch pas possible donc modif converti tes exception en function qui ecrive dans un fichier

#include "./BitcoinExchange.hpp"
#include <cctype>
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
	std::getline(inputFile, line);
	this->checkFirstLine(line);
	while(std::getline(inputFile, line))
	{
		this->addData(this->checkDateFormat(line),this->checkValueFormat(line));
	}
	inputFile.close();
	std::map<const std::string, const float>::iterator it;
	for(it = _CsvParsed.begin(); it != _CsvParsed.end(); ++it)
		std::cout << it->first << ' ' << it->second << std::endl;
}

void	BitcoinExchange::addData(std::string date, float value)
{
	this->_CsvParsed.insert(std::map<std::string, float>::value_type(date, value));
}

void	BitcoinExchange::checkFirstLine(const std::string &line)
{
	if(line != "date | value")
		throw BitcoinExchange::BadLineFormatException();
	return;
}

const std::string BitcoinExchange::checkDateFormat(const std::string &line)
{
	for(int i = 0; i < 10; ++i)
	{
		if(i == 4 || i == 7)
		{
			if (line[i] != '-')
				throw BitcoinExchange::BadDateFormatException();
		}
		else if(!std::isdigit(line[i]))
		{
			throw BitcoinExchange::BadDateFormatException();
		}
	}
	if(line[5] > '1' || (line[6] > '2' && line[5] > '1') || line[8] > '3' || (line[8] == '3' && line[9] > '1'))
		throw BitcoinExchange::NoArgFileException();
	if(line[10] != ' ' && line[11] != '|')
		throw BitcoinExchange::BadDateFormatException();
	std::string date = line.substr(0, 10);
	return (date);
}

float	BitcoinExchange::checkValueFormat(const std::string &line)
{
	unsigned long int i = 0;

	while(line[i] != '|')
		i++;
	if(line[i+2])
		i += 2;
	else
		throw BitcoinExchange::BadLineFormatException();
	std::string valuestr = line.substr(i, line.size());
	float value = atof(valuestr.c_str());
	if (value == 0 && valuestr[0] != '0')
		throw BitcoinExchange::BadLineFormatException();
	if(value < 0)
		throw BitcoinExchange::NotPosNumException();
	if(((valuestr.size() == 1 && valuestr[0] != '0') && value == 0) || value > 2147483648)
		throw BitcoinExchange::NotIntException();
	return(value);
}

const std::string BitcoinExchange::NoArgFileException::err() const throw()
{
	return("Error: could not open file.");
}

const std::string BitcoinExchange::BadLineFormatException::err() const throw()
{
	return("Error: Bad Line Format.");
}

const std::string BitcoinExchange::BadDateFormatException::err() const throw()
{
	return("Error: bad input => .");
}

const std::string BitcoinExchange::NotPosNumException::err() const throw()
{
	return("Error: not a positive number.");
}
const std::string BitcoinExchange::NotIntException::err() const throw()
{
	return("Error: too large number.");
}

// ----------Non_Members_Functions----------


