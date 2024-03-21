/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:14 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/21 17:53:45 by joakoeni         ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map<const std::string, const float> _CsvParsed;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		void				parseCsv(std::ifstream &inputFile);
		void				addData(std::string date, float value);
		void				checkFirstLine(const std::string &line);
		const std::string	checkDateFormat(const std::string &line);
		float			checkValueFormat(const std::string &line);
		const std::string	NoArgFile(void);
		const std::string 	BadLineFormat(void);
		const std::string 	BadDateFormat(void);
		const std::string	NotPosNumException(void);
		const std::string	NotInt(void);

	class NoArgFileException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
	class BadLineFormatException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
	class BadDateFormatException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
	class NotPosNumException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
	class NotIntException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
};

#endif
