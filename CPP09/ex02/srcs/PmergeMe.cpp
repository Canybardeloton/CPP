/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:23:59 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/16 15:28:47 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

Pmergeme::Pmergeme(unsigned int num)
{
}

Pmergeme::Pmergeme(const Pmergeme& copy) : _vec(copy._vec), _dqe(copy._dqe)
{
}

Pmergeme&	Pmergeme::operator=(const Pmergeme& copy)
{
	if (this != &copy)
	{
		this->_vec = copy._vec;
		this->_dqe = copy._dqe;
	}
	return (*this);
}
Pmergeme::~Pmergeme()
{
}

void	Pmergeme::before(const std::string& input)
{
	std::cout << "Before : " << input << std::endl;
}

void	Pmergeme::after(const std::string& final_input)
{
	std::cout << "After : " << final_input << std::endl;
}

bool	Pmergeme::checkInput(const std::string& input)
{
	if (input.size() > 5998)
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ')
			return (false);
	}
	return (true);
}

template<typename T>
void	Pmergeme::MergeSort(T& container, int left, int right)
{
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSort(container, left, mid);
	mergeSort(container, mid + 1, right);

	T temp(right - left + 1);
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (container[i] <= container[j])
			temp[k++] = container[i++];
		else
			temp[k++] = container[j++];
	}
	while (i <= mid)
		temp[k++] = container[i++];
	while (j <= right)
		temp[k++] = container[j++];
	for (i = 0; i < k; i++)
		container[left + i] = temp[i];
}

template <typename T>
std::vector<int>	Pmergeme::JacobsthalSequence(int n)
{
	std::vector<int> jacobsthal;

	if (n <= 0)
		return (jacobsthal);

	jacobsthal.push_back(0);
	if (n > 1)
		jacobsthal.push_back(1);

	for (int i = 2; i < n; i++)
	{
		int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
		jacobsthal.push_back(next);
	}
	return (jacobsthal);
}

void	Pmergeme::sortWithVector()
{
	if (_vec.empty()) return;

	// Stocker l'élément impair s'il existe
	int extraElement = -1;
	bool hasExtraElement = false;

	if (_vec.size() % 2 != 0) {
		extraElement = _vec.back();
		_vec.pop_back();
		hasExtraElement = true;
	}

	// Former des paires où le premier élément est le plus grand
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _vec.size(); i += 2) {
		if (_vec[i] > _vec[i+1])
			pairs.push_back(std::make_pair(_vec[i], _vec[i+1]));
		else
			pairs.push_back(std::make_pair(_vec[i+1], _vec[i]));
	}

	// Trier les paires par leur premier élément
	// (utilisation d'un tri par insertion pour la simplicité)
	for (size_t i = 1; i < pairs.size(); i++) {
		std::pair<int, int> key = pairs[i];
		int j = i - 1;

		while (j >= 0 && pairs[j].first > key.first) {
			pairs[j+1] = pairs[j];
			j--;
		}
		pairs[j+1] = key;
	}

	// Créer la chaîne principale avec les premiers éléments de chaque paire
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	// Insertion des éléments de pendChain dans mainChain
	// en utilisant la séquence de Jacobsthal

	// Insérer le premier élément de pendChain
	mainChain.insert(mainChain.begin(), pendChain[0]);

	// Générer la séquence de Jacobsthal
	std::vector<int> jacobsthalIdx = JacobsthalSequence(pendChain.size());

	// Insérer les éléments restants
	for (size_t i = 1; i < jacobsthalIdx.size() && i < pendChain.size(); i++) {
		int idx = jacobsthalIdx[i];
		if (idx < (int)pendChain.size()) {
			// Trouver la position d'insertion en utilisant la recherche binaire
			int val = pendChain[idx];
			int left = 0;
			int right = mainChain.size() - 1;

			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (mainChain[mid] < val)
					left = mid + 1;
				else
					right = mid - 1;
			}

			// Insérer à la position correcte
			mainChain.insert(mainChain.begin() + left, val);
		}
	}

	// Insérer l'élément impair s'il existe
	if (hasExtraElement) {
		// Trouver la position d'insertion pour l'élément impair
		int left = 0;
		int right = mainChain.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mainChain[mid] < extraElement)
				left = mid + 1;
			else
				right = mid - 1;
		}

		mainChain.insert(mainChain.begin() + left, extraElement);
	}

	// Mettre à jour le conteneur
	_vec = mainChain;
}