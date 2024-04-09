/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:54:24 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 13:41:39 by joakoeni         ###   ########.fr       */
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
		if(Pmergeme.checkArgs(argv[i]) == false)
		{
			std::cerr << "Error: bad arguments." << std::endl;
			std::cerr << "You send: " << arg << std::endl;
			std::cerr << "Arguments can only be a positive integer." << std::endl;
			return 0;
		}
	}
	Pmergeme.printDeque();
	startTime = clock() * 1000000.000000 / CLOCKS_PER_SEC;
	Pmergeme.buildSequences();
	endTime = clock() * 1000000.000000 / CLOCKS_PER_SEC;
	timeOne = (endTime - startTime);
	startTime = clock() * 1000000.000000 / CLOCKS_PER_SEC;
	Pmergeme.buildFinalContainer();
	endTime = clock() * 1000000.000000 / CLOCKS_PER_SEC;
	timeTwo = (endTime - startTime);
	Pmergeme.printMap();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::multimap : " << timeOne << " us" << std::endl;
	std::cout << "Time to process a range of "<< Pmergeme.sizeMap() << " elements with std::map : " << timeTwo << " us" << std::endl;
}

