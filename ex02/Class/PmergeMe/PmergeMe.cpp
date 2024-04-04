/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:43:18 by joakoeni          #+#    #+#             */
/*   Updated: 2024/04/04 17:11:28 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

// ----------Constructors----------

PmergeMe::PmergeMe()
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

void	PmergeMe::deleteInDeque(int i)
{
	for(int j = 0; j != i; j++)
		this->_args.erase(0);
}

void	PmergeMe::addToMultiMap(int i)
{

}

int	PmergeMe::decreaseOrIncreaseSequence(void)
{
	if(this->_args[0] < this->_args[1])
		return -1;
	else if(this->_args[0] > this->_args[1])
		return 1;
	else
		return 0;
}

void	PmergeMe::buildSequences(void)
{
	int sens = this->decreaseOrIncreaseSequence();
	int i = 0;
	if(sens == -1)
	{
		for(i = 0; this->_args[i] < this->_args[i+1]; i++){}
		this->addToMultiMap(i);
		this->deleteInDeque(i);
	}
	else if (sens == 1)
	{
		for(i = 0; this->_args[i] > this->_args[i+1]; i++){}
		this->addToMultiMap(i);
		this->deleteInDeque(i);
	}
	else if (sens == 0)
	{

		this->deleteInDeque(i);
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


