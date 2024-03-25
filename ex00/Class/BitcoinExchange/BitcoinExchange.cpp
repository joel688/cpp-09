/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/25 14:05:05 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ne pass pas le test si pas de pipe ou value ou espace a la place de precedemment cite
// try catch pas possible donc modif converti tes exception en function qui ecrive dans un fichier

#include "./BitcoinExchange.hpp"

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

void	BitcoinExchange::printContainer(void)
{
	std::map<const std::string, const std::string>::iterator it;
	for(it = _CsvParsed.begin(); it != _CsvParsed.end(); ++it)
	{
		if(it->second == "")
			std::cout << it->first << std::endl;
		else if(it->first == "")
			std::cout << it->second << std::endl;
		else
			std::cout << it->first << " | " << it->second << std::endl;
	}
}

void BitcoinExchange::parseCsv(std::ifstream &inputFile)
{
	std::string line, date, value;
	std::getline(inputFile, line);
	this->checkFirstLine(line);
	while(std::getline(inputFile, line))
	{
		date = this->checkDateFormat(line);
		value = this->checkValueFormat(line);
		if(date[0] == 'E')
			this->addData(date, "");
		else if (value[0] == 'E')
			this->addData("", value);
		else
			this->addData(date, value);
	}
	inputFile.close();
	this->printContainer();
}

void	BitcoinExchange::addData(std::string date, std::string value)
{
	this->_CsvParsed.insert(std::map<std::string, std::string>::value_type(date, value));
}

const std::string	BitcoinExchange::checkFirstLine(const std::string &line)
{
	if(line != "date | value")
		return (this->BadLineFormat());
	return(line);
}

const std::string BitcoinExchange::checkDateFormat(const std::string &line)
{

	std::string date = line.substr(0, 10);
	for(int i = 0; i < 10; ++i)
	{
		if(i == 4 || i == 7)
		{
			if (line[i] != '-')
				return (this->BadDateFormat(date));
		}
		else if(!std::isdigit(date[i]))
		{
			return (this->BadDateFormat(date));
		}
	}
	if(line[5] > '1' || (line[6] > '2' && line[5] > '1') || line[8] > '3' || (line[8] == '3' && line[9] > '1'))
		return (this->BadDateFormat(date));
	return (date);
}

const std::string	BitcoinExchange::checkValueFormat(const std::string &line)
{
	unsigned long int	i = 0;
	bool				is_sep = false;

	while(line[i] && line[i] != ',')
	{
		i++;
		if(line[i] == ',')
			is_sep = true;
	}
	if(is_sep == true && line[i+1])
		i += 1;
	else
		return (this->BadLineFormat());
	std::string valuestr = line.substr(i, line.size());
	float value = atof(valuestr.c_str());
	if (value == 0 && valuestr[0] != '0')
		return (this->BadLineFormat());
	if(value < 0)
		return (this->NotPosNum());
	if(((valuestr.size() == 1 && valuestr[0] != '0') && value == 0) || value > 2147483648)
		return (this->NotInt());
	return(valuestr);
}

const std::string	BitcoinExchange::BadLineFormat(void)
{
	return("Error: Bad Line Format.");
}

const std::string	BitcoinExchange::BadDateFormat(const std::string &line)
{
	return("Error: bad input => " + line + ".");
}

const std::string	BitcoinExchange::NotPosNum(void)
{
	return("Error: not a positive number.");
}
const std::string	BitcoinExchange::NotInt(void)
{
	return("Error: too large number.");
}

const std::string	BitcoinExchange::NoArgFileException::err() const throw()
{
	return("Error: could not open file.");
}
// ----------Non_Members_Functions----------


