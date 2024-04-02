/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:14 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/02 18:50:58 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>

struct StringCompare
{
    bool operator()(const std::string& a, const std::string& b) const
	{
        return a < b;
    }
};

class BitcoinExchange
{
	private:
		std::vector<std::pair<std::string, std::string> > _TxtParsed;
		std::map<std::string, std::string> _DataBaseParsed;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange&								operator=(const BitcoinExchange& src);
		void											parseCsv(std::ifstream &inputFile);
		void											addData(const std::string date, std::string value);
		void											addToDataBase(const std::string date, std::string value);
		const std::string 								checkFirstLine(const std::string &line);
		const std::string								checkDateFormat(const std::string &line);
		const std::string								checkValueFormat(const std::string &line);
		const std::string								checkValueFormatCsv(const std::string &line);
		const std::string 								BadLineFormat(void);
		const std::string 								BadDateFormat(const std::string &line);
		const std::string								NotPosNum(void);
		const std::string								NotInt(void);
		const std::string								NoArgFiles(void);
		void											printContainer(void);
		void											printDataBase(void);
		void											parseIntput(std::ifstream &inputFile);
		std::map<std::string, std::string>::iterator	findLowerKey(std::string date);
		void											printResult(void);
	
};

#endif
