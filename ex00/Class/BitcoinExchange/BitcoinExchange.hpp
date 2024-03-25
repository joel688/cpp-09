/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:14 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/25 14:20:43 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// 1 = parse csv stock in container
// 2 = display it  with good form= value multiplied by the exchange rate according to the date indicated

#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<const std::string, const std::string> _CsvParsed;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		void				parseCsv(std::ifstream &inputFile);
		void				addData(const std::string date, std::string value);
		const std::string 	checkFirstLine(const std::string &line);
		const std::string	checkDateFormat(const std::string &line);
		const std::string	checkValueFormat(const std::string &line);
		const std::string 	BadLineFormat(void);
		const std::string 	BadDateFormat(const std::string &line);
		const std::string	NotPosNum(void);
		const std::string	NotInt(void);
		void				printContainer(void);
		void				parseIntput(std::ifstream &inputFile);
	class NoArgFileException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
};

#endif
