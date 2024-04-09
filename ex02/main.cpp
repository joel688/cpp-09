/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:54:24 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 11:55:08 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Class/PmergeMe/PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	PmergeMe Pmergeme;
	double startTime;
	double endTime;
	double timeOne;
	double timeTwo;
	for(int i = 1; i != argc; i++)
	{
		std::string arg = argv[i];
		if((!(arg == "shuf" && i == 1)) && !(arg == "-i" && i == 2) && !(arg == "-n" && i == 4))
		{
			if(Pmergeme.checkArgs(argv[i]) == false)
			{
				std::cerr << "Error: bad arguments." << std::endl;
				std::cerr << "You send: " << arg << std::endl;
				std::cerr << "Arguments can only be a positive integer." << std::endl;
				return 0;
			}
		}
	}
	Pmergeme.printDeque();
	startTime = clock() * 1000000 / CLOCKS_PER_SEC;
	Pmergeme.buildSequences();
	endTime = clock() * 1000000 / CLOCKS_PER_SEC;
	timeOne = (endTime - startTime) / 10000;
	startTime = clock() * 1000000 / CLOCKS_PER_SEC;
	Pmergeme.buildFinalContainer();
	endTime = clock() * 1000000 / CLOCKS_PER_SEC;
	timeTwo = (endTime - startTime) / 10000;
	Pmergeme.printMap();
	std::cout << "Time to process a range of 3000 elements with std::multimap : " << timeOne << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::map : " << timeTwo << std::endl;
}

