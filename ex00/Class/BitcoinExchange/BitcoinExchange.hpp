/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:46:14 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/18 09:46:16 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// 1 = parse csv stock in container
// 2 = display it  with good form= value multiplied by the exchange rate according to the date indicated

#include <exception>
#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		const std::map<const std::string, const float> CsvParsed;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		const 				std::string getLine() const;
		const				std::string splitLineDate(const std::string Line) const;
		const				float splitLineValue(const std::string Line) const;
		void				addData(const std::string& Date, const float Value);
	
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
