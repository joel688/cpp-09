/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:11 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/03 16:41:54 by joakoeni         ###   ########.fr       */
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
	this->_TxtParsed = src._TxtParsed;
	this->_DataBaseParsed = src._DataBaseParsed;
	return(*this);
}

// ----------Members_Functions----------

bool	BitcoinExchange::isCsvEmpty(const std::string& inputCsv)
{
	std::ifstream file(inputCsv.c_str());
	return file.peek() == std::ifstream::traits_type::eof();
}

void	BitcoinExchange::printResult(void)
{
	std::vector<std::pair<std::string, std::string> >::iterator it1 = this->_TxtParsed.begin();

	while(it1 != this->_TxtParsed.end())
	{
		if(it1->first[0] == 'E' || it1->second[0] == 'E' || findLowerKey(it1->first)->first[0] == 'E' || findLowerKey(it1->first)->second[0] == 'E') 
		{
			if(it1->second == "")
				std::cout << it1->first << std::endl;
			else if(it1->first == "")
				std::cout << it1->second << std::endl;
			else if(findLowerKey(it1->first)->first[0] == 'E')
				std::cout << findLowerKey(it1->first)->first << std::endl;
			else if(findLowerKey(it1->first)->second[0] == 'E')
				std::cout << findLowerKey(it1->first)->second << std::endl;
		}
		else
		{
			float value = std::atof(findLowerKey(it1->first)->second.c_str());
			float quantity = std::atof(it1->second.c_str());
			float to_print = value * quantity;
			std::cout << it1->first << " => " << it1->second << " = ";
			std::cout << to_print << std::endl;
		}
		it1++;
	}
}

std::map<std::string, std::string>::iterator	BitcoinExchange::findLowerKey(std::string date)
{
	std::map<std::string, std::string>::iterator it = this->_DataBaseParsed.lower_bound(date);
	std::map<std::string, std::string>::iterator end = this->_DataBaseParsed.end();
	end--;
	if(!(it == this->_DataBaseParsed.begin()))
	{
		if (it == this->_DataBaseParsed.begin() || (it != this->_DataBaseParsed.end() && date.compare((--it)->first) < it->first.compare(date)))
			--it;
		else if(it == this->_DataBaseParsed.end())
			it = end;
		else
			++it;
	}
	return it;
}

void	BitcoinExchange::printContainer(void)
{
	std::vector<std::pair<std::string, std::string> >::iterator it;
	for(it = _TxtParsed.begin(); it != _TxtParsed.end(); ++it)
	{
		if(it->second == "")
			std::cout << it->first << std::endl;
		else if(it->first == "")
			std::cout << it->second << std::endl;
		else
			std::cout << it->first << " | " << it->second << std::endl;
	}
}

void	BitcoinExchange::printDataBase(void)
{
	std::map<std::string, std::string>::iterator it;
	for(it = _DataBaseParsed.begin(); it != _DataBaseParsed.end(); ++it)
	{
		if(it->second == "")
			std::cout << it->first << std::endl;
		else if(it->first == "")
			std::cout << it->second << std::endl;
		else
			std::cout << it->first << " | " << it->second << std::endl;
	}
}

void BitcoinExchange::parseIntput(std::ifstream &inputFile)
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
}

void BitcoinExchange::parseCsv(std::ifstream &inputFile)
{
	std::string line, date, value;
	std::getline(inputFile, line);
	this->checkFirstLine(line);
	while(std::getline(inputFile, line))
	{
		date = this->checkDateFormat(line);
		value = this->checkValueFormatCsv(line);
		if(date[0] == 'E')
			this->addToDataBase(line.substr(0, 10), date);
		else
			this->addToDataBase(date, value);
		this->addToDataBase(date, value);
	}
	inputFile.close();
}

void	BitcoinExchange::addData(std::string date, std::string value)
{
	this->_TxtParsed.push_back(std::make_pair(date, value));
}

void	BitcoinExchange::addToDataBase(std::string date, std::string value)
{
	this->_DataBaseParsed.insert(std::map<std::string, std::string>::value_type(date, value));
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

const std::string	BitcoinExchange::checkValueFormatCsv(const std::string &line)
{
	unsigned long int	i = 0;
	bool				is_sep = false;

	while(line[i] && line[i] != ',')
	{
		i++;
		if(line[i] == ',')
			is_sep = true;
	}
	if(is_sep == true && line[i + 1])
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

const std::string	BitcoinExchange::checkValueFormat(const std::string &line)
{
	unsigned long int	i = 0;
	bool				is_sep = false;

	while(line[i] && line[i] != '|')
	{
		i++;
		if(line[i] == '|')
			is_sep = true;
	}
	if(is_sep == true && line[i + 2])
		i += 2;
	else
		return (this->BadLineFormat());
	std::string valuestr = line.substr(i, line.size());
	float value = atof(valuestr.c_str());
	if (value == 0 && valuestr[0] != '0')
		return (this->BadLineFormat());
	if(value < 0)
		return (this->NotPosNum());
	if(((valuestr.size() == 1 && valuestr[0] != '0') && value == 0) || value > 1000)
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

const std::string	BitcoinExchange::NoArgFiles(void)
{
	return("Error: could not open file.");
}
// ----------Non_Members_Functions----------


