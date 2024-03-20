/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:14 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/20 13:44:18 by joakoeni         ###   ########.fr       */
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
		std::string			splitLineDate(const std::string &line);
		float 				splitLineValue(const std::string &line);
		void				addData(std::string date, float value);
		void				checkFormat(std::string line);
	
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
	class BadValueException : public std::exception
	{
		public:
			const std::string err() const throw();
	};
};

#endif
