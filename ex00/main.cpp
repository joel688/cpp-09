/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:18:06 by joakoeni          #+#    #+#             */
/*   Updated: 2024/03/22 14:22:36 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/BitcoinExchange/BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if(argc != 2)
		throw BitcoinExchange::NoArgFileException();
	try
	{

		std::ifstream inputFile(argv[1]);
		if(!inputFile.is_open())
			throw BitcoinExchange::NoArgFileException();
		btc.parseCsv(inputFile);
		
	}
	catch(BitcoinExchange::NoArgFileException &e)
	{
		std::cerr << e.err() << std::endl;
	}
	
	return 0;
}
