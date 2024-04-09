/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:43:18 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/09 11:28:18 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <iostream>


//GERER LES DOUBLONS PRENDRE UNE DECISION

// ----------Constructors----------

PmergeMe::PmergeMe() : nb_sequence(0)
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
	return;
}
// ----------Deconstructors----------

PmergeMe::~PmergeMe()
{
	return;
}

// ----------Setters----------

// ----------Getters----------

// ----------Operators_Overloaders----------
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	this->_args = src._args;
    return *this;
}
// ----------Members_Functions----------

void PmergeMe::printDeque(void)
{
    std::deque<int>::const_iterator it;
    std::cout << "Before: ";
    for (it = this->_args.begin(); it != this->_args.end(); ++it)
	{
        std::cout << *it;
        if (it != this->_args.end() - 1)
            std::cout << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::printMap(void)
{
	std::cout << "After:";
    for (std::map<int, int>::const_iterator it = this->_final.begin(); it != this->_final.end(); ++it) 
	{
        std::cout << " ";
        std::cout << it->first;
    }
	std::cout << std::endl;
}

void	PmergeMe::buildFinalContainer(void)
{
	int i = 0;
	while(!this->_sequences.empty())
	{
		std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> range = this->_sequences.equal_range(i);
		for(std::multimap<int, int>::iterator it = range.first; it != range.second; ++it)
			this->_final.insert(std::make_pair(it->second, 0));
		this->_sequences.erase(i);
		i++;
	}
}

void	PmergeMe::deleteInDeque(int i)
{
	while(i-- != -1)
		this->_args.pop_front();
}

void	PmergeMe::addToMultiMap(int i)
{
	while(i != -1)
		this->_sequences.insert(std::make_pair(this->nb_sequence, this->_args[i--]));
	this->nb_sequence++;
}

int	PmergeMe::decreaseOrIncreaseSequence(void)
{
	if(this->_args.size() == 1)
		return 0;
	if(this->_args[0] < this->_args[1])
		return -1;
	else if(this->_args[0] > this->_args[1])
		return 1;
	return 0;
}

void	PmergeMe::buildSequences(void)
{
	while(!this->_args.empty())
	{
		int sens = this->decreaseOrIncreaseSequence();
		int i = 0;
		if(sens == -1)
		{
			for(i = 0; this->_args[i] < this->_args[i+1]; ++i){}
			this->addToMultiMap(i);
			this->deleteInDeque(i);
		}
		else if (sens == 1)
		{
			for(i = 0; this->_args[i] > this->_args[i+1]; ++i){}
			this->addToMultiMap(i);
			this->deleteInDeque(i);
		}
		else if(sens == 0)
		{
			this->addToMultiMap(i);
			this->deleteInDeque(i);
		}
	}
}

bool PmergeMe::checkArgs(char *arg)
{
	char* endptr;
    double val = std::strtod(arg, &endptr);
	int mod = val;
	if(val - mod != 0)
		return false;
    if((*arg != '\0' && *endptr == '\0' && val >= 0) == 0)
		return false;
	this->_args.push_back(val);
	return true;
}

// ----------Non_Members_Functions----------
